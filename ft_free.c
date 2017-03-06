/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:40:31 by yderosie          #+#    #+#             */
/*   Updated: 2016/12/20 15:40:38 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	look_list(void *ptr, t_block *listtiny, t_block *listsmall)
{
	t_block	*move;

	move = listtiny;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
	{
		move->free = 1;
		return (1);
	}
	move = listsmall;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
	{
		move->free = 1;
		return (1);
	}
	return (0);
}

size_t	large_list(void *ptr, t_block **block)
{
	t_block *move;

	move = *block;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
	{
		move->free = 1;
		return (move->size);
	}
	return (0);
}

void	ft_free(void *ptr)
{
	t_zone	**zonetiny;
	t_zone	**zonesmall;
	size_t	size;

	zonetiny = init_zone(1);
	zonesmall = init_zone(2);
	size = 0;
	if (look_list(ptr, (*zonetiny)->zoneblock, (*zonesmall)->zoneblock) == 0)
	{
		size = large_list(ptr, init_list_large());
		if (size == 0)
			return ;
		else
			printf("%d\n", munmap(ptr, size));
	}
}