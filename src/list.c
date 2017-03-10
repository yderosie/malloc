/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:43:17 by yderosie          #+#    #+#             */
/*   Updated: 2017/03/10 15:43:18 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*new_p_zone(t_zone **move, int *j)
{
	size_t	size_zone_list;
	int		i;
	void	*p;

	size_zone_list = sizeof(t_zone);
	i = 0;
	while ((*move)->next != NULL)
	{
		(*move) = (*move)->next;
		i++;
	}
	if (((size_zone_list * i + size_zone_list) -
		((*move)->nbnewalloc * LEN_LIST)) >= (LEN_LIST))
	{
		(*j)++;
		p = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
	}
	else
		p = (*move) + size_zone_list;
	return (p);
}

void		new_zone(t_zone **zone, size_t size)
{
	t_zone	*new;
	t_zone	*move;
	int		j;

	move = (*zone);
	j = 0;
	new = new_p_zone(&move, &j);
	new->zone = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
	new->zonenow = NULL;
	new->zoneblock = NULL;
	new->nballoczone = 0;
	new->zonesize = 0;
	new->nbnewalloc = move->nbnewalloc + j;
	new->next = NULL;
	move->next = new;
}

static void	*new_p_block(t_block **move, int *j)
{
	size_t	block_struct;
	void	*b;
	int		i;

	i = 0;
	block_struct = sizeof(t_block);
	while ((*move)->next != NULL)
	{
		(*move) = (*move)->next;
		i++;
	}
	if (((block_struct * i + block_struct) -
		((*move)->nbnewalloc * LEN_LIST)) >= (LEN_LIST))
	{
		(*j)++;
		b = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, 0, 0);
	}
	else
		b = (void *)(*move) + block_struct;
	return (b);
}

void		set_block(t_block *block, size_t size, void *ptr)
{
	t_block *b;
	t_block *move;
	int		j;

	move = block;
	j = 0;
	b = new_p_block(&move, &j);
	b->size = size;
	b->ptr = ptr;
	b->free = 0;
	b->nbnewalloc = move->nbnewalloc + j;
	b->next = NULL;
	move->next = b;
}
