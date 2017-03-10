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

static int	control_size(size_t size, size_t size_now, size_t maxsize)
{
	if (size_now + size > maxsize)
		return (0);
	else
		return (1);
}

static void	*free_zone(t_block *block, size_t size)
{
	t_block *move;

	move = block;
	while (move != NULL && move->free == 0)
	{
		if (move->size >= size)
		{
			move->free = 0;
			return (move->ptr);
		}
		move = move->next;
	}
	return (NULL);
}

static void	*add_block_alloc(t_zone **zone, size_t size, size_t zonesize)
{
	void	*ptr;
	t_zone	*move;

	move = (*zone);
	while (move != NULL)
	{
		if ((ptr = free_zone((*zone)->zoneblock, size)) != NULL)
			break ;
		else if (control_size(size, move->zonesize, zonesize))
		{
			ptr = move->zonenow;
			set_block((*zone)->zoneblock, size, ptr);
			move->zonenow = move->zonenow + size;
			move->zonesize += size;
			move->nballoczone++;
			break ;
		}
		move = move->next;
	}
	if (move == NULL)
	{
		new_zone(zone, zonesize);
		ptr = add_block_alloc(zone, size, zonesize);
	}
	return (ptr);
}

static void	*select_zone(t_zone **zonetiny, t_zone **zonesmall, size_t size)
{
	void *ptr;

	ptr = NULL;
	if (size > (SMALL / 100))
	{
		ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
		set_block(*(init_list_large()), size, ptr);
	}
	else if (size <= (SMALL / 100) && size > (TINY / 100))
		ptr = add_block_alloc(zonesmall, size, SMALL);
	else if (size <= (TINY / 100))
		ptr = add_block_alloc(zonetiny, size, TINY);
	return (ptr);
}

void		*ft_malloc(size_t size)
{
	void		*ptr;
	t_zone		**zonetiny;
	t_zone		**zonesmall;
	static int	first = 0;

	ptr = NULL;
	if (first == 0)
	{
		zonetiny = init(TINY);
		zonesmall = init(SMALL);
		first = 1;
	}
	else
	{
		zonetiny = init_zone_tiny();
		zonesmall = init_zone_small();
	}
	ptr = select_zone(zonetiny, zonesmall, size);
	return (ptr);
}
