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

void	show_alloc_mem(void)
{
	t_zone	**zonetiny;
	t_zone	**zonesmall;
	t_block	*move;
	size_t	total_size;

	zonetiny = init_zone(1);
	zonesmall = init_zone(2);
	total_size = 0;
	move = (*zonetiny)->zoneblock;
	printf("TINY : %p\n", (*zonetiny)->zone);
	while (move != NULL)
	{
		if (move->free == 0)
		{
			printf("%p - %p : %zu octects\n", move->ptr, move->ptr + move->size - 1, move->size);
			total_size += move->size;
		}
		move = move->next;
	}
	move = (*zonesmall)->zoneblock;
	printf("SMALL : %p\n", (*zonesmall)->zone);
	while (move != NULL)
	{
		if (move->free == 0)
		{
			printf("%p - %p : %zu octects\n", move->ptr, move->ptr + move->size - 1, move->size);
			total_size += move->size;
		}
		move = move->next;
	}
	move = *(init_list_large());
	printf("LARGE : %p\n", (*zonesmall)->zone);
	while (move != NULL)
	{
		if (move->free == 0)
		{
			printf("%p - %p : %zu octects\n", move->ptr, move->ptr + move->size - 1, move->size);
			total_size += move->size;
		}
		move = move->next;
	}
	printf("Total : %zu octects\n", total_size);
}

void	print_list(t_block *block)
{
	t_block *move;
	int i;

	i = 0;
	move = block;
	while (move != NULL && move->free == 0)
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
	size_t	size_zone_list;
	int		i;

	move = (*zone);
	size_zone_list = sizeof(t_zone);
	i = 0;
	while (move->next != NULL)
	{
		move = move->next;
		i++;
	}
	if (size_zone_list * i > LEN_LIST)
		new = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	else
		new = move + size_zone_list;
	new->zone = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	new->zonenow = NULL/* mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);*/;
	new->zoneblock = NULL;
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
	int		i;

	move = block;
	i = 0;
	block_struct = sizeof(t_block);
	while (move->next != NULL)
	{
		move = move->next;
		i++;
	}
	if (block_struct * i > LEN_LIST)
		b = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	else
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
	b->free = 1;
	b->first = 1;
	b->next = NULL;
}

void	add_block_list(t_block *block, size_t size, void *ptr)
{
	if (block->first == 0)
		add_first_segment(block, size, ptr);
	else
		set_segment(block, size, ptr);
}

void	*add_block_alloc(t_zone **zone, size_t size, size_t zonesize)
{
	void	*ptr;
	t_zone	*move;

	move = (*zone);
	while (move != NULL)
	{
		if (control_size(size, move->zonesize, zonesize))
		{
			ptr = move->zonenow;
			add_block_list((*zone)->zoneblock, size, ptr);
			move->zonenow = move->zonenow + size;
			move->zonesize += size;
			move->nballoczone++;
			break ;
		}
		else
			move = move->next;
	}
	if (move == NULL)
	{
		new_zone(zone, zonesize);
		ptr = add_block_alloc(zone, size, zonesize);
	}
	return (ptr);
}

void	*select_zone(t_zone **zonetiny, t_zone **zonesmall, size_t size)
{
	void *ptr;

	ptr = NULL;
	if (size > (SMALL / 100))
	{
		ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		set_segment(*(init_list_large()), size, ptr);
	}
	else if (size < (SMALL / 100) && size > (TINY / 100))
	{
		ptr = add_block_alloc(zonesmall, size, SMALL);
	}
	else if (size < (TINY / 100))
	{
		ptr = add_block_alloc(zonetiny, size, TINY);
	}
	return (ptr);
}

t_block **init_list_large(void)
{
	static t_block	*largelist;
	static int		first = 0;

	if (first == 0)
	{
		largelist = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		add_first_segment(largelist, 0, largelist);
		first = 1;
	}
	return (&largelist);
}

t_zone	**init_zone(int i)
{
	static t_zone *zonetiny;
	static t_zone *zonesmall;
	static int first = 0;

	if (first == 0)
	{
		zonetiny = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		zonesmall = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
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
	(*zone)->zoneblock = mmap(NULL, LEN_LIST, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	add_first_segment((*zone)->zoneblock, 0, (*zone)->zoneblock);
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
	else
	{
		zonetiny = init_zone(1);
		zonesmall = init_zone(2);
	}
	printf("tiny malloc == %p %p\n", (*zonetiny)->zone, (*zonetiny)->zonenow);
	printf("small malloc == %p %p\n", (*zonesmall)->zone, (*zonesmall)->zonenow);

	printf("ptr = %p\n", ptr);
	ptr = select_zone(zonetiny, zonesmall, size);
	print_list((*zonetiny)->zoneblock);
	print_list((*zonesmall)->zoneblock);
	return (ptr);
}
