/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:40:48 by yderosie          #+#    #+#             */
/*   Updated: 2016/12/20 15:40:52 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	init(t_zone_alloc *t_zone)
{
	printf("%d %d\n", getpagesize(), getpagesize() *2);
	t_zone->tiny = mmap(NULL, getpagesize(),PROT_READ | PROT_WRITE, MAP_SHARED, 0, 0);
	t_zone->small = mmap(NULL, getpagesize() * 2,PROT_READ | PROT_WRITE, MAP_SHARED, 0, 0);
	t_zone->tinynow = &t_zone->tiny;
	t_zone->smallnow = &t_zone->small;
	t_zone->nballoctiny = 0;
	t_zone->nballocsmall = 0;
	t_zone->tinysize = 0;
	t_zone->smallsize = 0;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;
	static t_zone_alloc t_zone;
	static int first = 0;

	ptr = NULL;
	if (first == 0)
	{
		init(&t_zone);
		first = 1;
	}
	if (size > ((getpagesize() * 2) / 100))
		ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, 0, 0);
	else if (size < ((getpagesize() * 2) / 100) && size > ((getpagesize()) / 100))
	{
		ptr = &t_zone.smallnow;
		t_zone.smallnow = t_zone.smallnow + size + 2;
		t_zone.smallsize += size + 2;
	}
	else if (size < ((getpagesize()) / 100))
	{
		ptr = &t_zone.tinynow;
		t_zone.tinynow = t_zone.tinynow + size + 2;
		t_zone.tinysize += size + 2;
	}
	return ptr;
}
