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

void	print_list(t_block *block)
{
	t_block *move;
	int i;

	i = 0;
	move = block;
	while (move != NULL)
	{
		printf("{alloc nb = %d, size = %zu, ptr = %p}\n", i, move->size, move->ptr);
		move = move->next;
		i++;
	}
}

void	new_zone(t_zone **zone, size_t size)
{
	t_zone	*new;
	t_zone	*move;
	size_t	size_zone;

	move = (*zone);
	size_zone = sizeof(t_zone);
	while (move->next != NULL)
		move = move->next;
	new = move + size_zone;
	new->zone = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	new->zonenow = new->zone;
	new->zoneblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	new->nballoczone = 0;
	new->zonesize = 0;
	new->next = NULL;
	move->next = new;
}

int 	control_size(size_t size,size_t size_now, size_t maxsize)
{
	if (size_now + size > maxsize)
		return (0);
	else
		return (1);
}

void	set_segment(t_block *block, size_t size, void *ptr)
{
	size_t block_struct;
	t_block *b;
	t_block *move;

	move = block;
	block_struct = sizeof(t_block);
	while (move->next != NULL)
		move = move->next;
	b = move + block_struct;
	b->size = size;
	b->ptr = ptr;
	b->free = 0;
	b->first = 0;
	b->next = NULL;
	move->next = b;
}

void	add_first_segment(t_block *block, size_t size, void *ptr)
{
	t_block *b;

	b = block;
	b->size = size;
	b->ptr = ptr;
	b->free = 0;
	b->first = 1;
	b->next = NULL;
}

void	check_list(t_block *block, size_t size, void *ptr)
{
	if (block->first == 0)
	{
		add_first_segment(block, size, ptr);
	}
	else
		set_segment(block, size, ptr);
}

void	*add_small_alloc(t_zone **zone, size_t size)
{
	void	*ptr;
	if (control_size(size, (*zone)->zonesize, SMALL))
	{
		ptr = (*zone)->zonenow;
		check_list((*zone)->zoneblock, size, ptr);
		(*zone)->zonenow = (*zone)->zonenow + size;
		(*zone)->zonesize += size;
		(*zone)->nballoczone++;
	}
	return (ptr);
}

void	*add_tiny_alloc(t_zone **zone, size_t size)
{
	void	*ptr;
	if (control_size(size, (*zone)->zonesize, TINY))
	{
		ptr = (*zone)->zonenow;
		check_list((*zone)->zoneblock, size, ptr);
		(*zone)->zonenow = (*zone)->zonenow + size;
		(*zone)->zonesize += size;
		(*zone)->nballoczone++;
	}
	return (ptr);
}

void	*select_zone(t_zone **zonetiny, t_zone **zonesmall, size_t size)
{
	void *ptr;

	if (size > (SMALL / 100))
	{
		ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		//check_list((*zone)->largeblock, size, ptr);
	}
	else if (size < (SMALL / 100) && size > (TINY / 100) && (size + (*zonesmall)->zonesize) < SMALL)
		ptr = add_small_alloc(zonesmall, size);
	else if (size < (TINY / 100) && (size + (*zonetiny)->zonesize) < TINY)
		ptr = add_tiny_alloc(zonetiny, size);
	return (ptr);
}

t_zone	**init_zone(int i)
{
	static t_zone *zonetiny;
	static t_zone *zonesmall;
	static int first = 0;


	if (first == 0)
	{
		zonetiny = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		zonesmall = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		first = 1;
	}

	if (i == 1)
		return (&zonetiny);
	else
		return(&zonesmall);
}

t_zone	**init(size_t size)
{
	t_zone **zone;

	if (size == TINY)
		zone = init_zone(1);
	else
		zone = init_zone(2);
	printf("%d %d\n", TINY, SMALL);
	(*zone)->zone = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	(*zone)->zonenow = (*zone)->zone;
	(*zone)->zoneblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	(*zone)->nballoczone = 0;
	(*zone)->zonesize = 0;
	printf("tiny init == %p %p\n", (*zone)->zone, (*zone)->zonenow);
	(*zone)->next = NULL;
	return ((zone));
}

void	*ft_malloc(size_t size)
{
	void		*ptr;
	t_zone		**zonetiny;
	t_zone		**zonesmall;
	static int 	first = 0;

	ptr = NULL;
	if (first == 0)
	{
		zonetiny = init(TINY);
		zonesmall = init(SMALL);
		first = 1;
	}
	printf("tiny malloc == %p %p\n", (*zonetiny)->zone, (*zonetiny)->zonenow);
	printf("small malloc == %p %p\n", (*zonesmall)->zone, (*zonesmall)->zonenow);
	
	printf("ptr = %p\n", ptr);
	ptr = select_zone(zonetiny, zonesmall, size);
	print_list((*zonetiny)->zoneblock);
	print_list((*zonesmall)->zoneblock);
	return (ptr);
}
