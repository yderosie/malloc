/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:41:17 by yderosie          #+#    #+#             */
/*   Updated: 2016/12/20 15:41:18 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t	look_list(void *ptr, t_block *listtiny, t_block *listsmall)
{
	t_block	*move;

	move = listtiny;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
		return (1);
	move = listsmall;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
		return (1);
	return (0);
}

static size_t	large_list(void *ptr, t_block **block)
{
	t_block *move;

	move = *block;
	while (move != NULL && move->ptr != ptr)
		move = move->next;
	if (move != NULL)
		return (1);
	return (0);
}

void			*ft_realloc(void *ptr, size_t size)
{
	void	*new;
	t_zone	**zonetiny;
	t_zone	**zonesmall;

	if (ptr == NULL)
		return (NULL);
	zonetiny = init_zone_tiny();
	zonesmall = init_zone_small();
	if (look_list(ptr, (*zonetiny)->zoneblock, (*zonesmall)->zoneblock) == 0)
	{
		if (large_list(ptr, init_list_large()) == 0)
			return (NULL);
	}
	new = ft_malloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	ft_free(ptr);
	return (new);
}
