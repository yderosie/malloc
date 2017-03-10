/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:37:08 by yderosie          #+#    #+#             */
/*   Updated: 2017/03/10 15:37:10 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	add_first_block(t_block *block, size_t size, void *ptr)
{
	t_block *b;

	b = block;
	b->size = size;
	b->ptr = ptr;
	b->free = 1;
	b->nbnewalloc = 0;
	b->next = NULL;
}

t_block		**init_list_large(void)
{
	static t_block	*largelist;
	static int		first = 0;

	if (first == 0)
	{
		largelist = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
		add_first_block(largelist, 0, largelist);
		first = 1;
	}
	return (&largelist);
}

t_zone		**init_zone_tiny(void)
{
	static t_zone	*zonetiny;
	static int		first = 0;

	if (first == 0)
	{
		zonetiny = mmap(NULL, 100, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
		first = 1;
	}
	return (&zonetiny);
}

t_zone		**init_zone_small(void)
{
	static t_zone	*zonesmall;
	static int		first = 0;

	if (first == 0)
	{
		zonesmall = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
		first = 1;
	}
	return (&zonesmall);
}

t_zone		**init(size_t size)
{
	t_zone **zone;

	if (size == TINY)
		zone = init_zone_tiny();
	else
		zone = init_zone_small();
	(*zone)->zone = mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANON, 0, 0);
	(*zone)->zonenow = (*zone)->zone;
	(*zone)->zoneblock = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANON, 0, 0);
	add_first_block((*zone)->zoneblock, 0, (*zone)->zoneblock);
	(*zone)->nballoczone = 0;
	(*zone)->nbnewalloc = 0;
	(*zone)->zonesize = 0;
	(*zone)->next = NULL;
	return ((zone));
}
