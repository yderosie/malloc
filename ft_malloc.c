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

void	new_zone(t_alloc **zone)
{
	t_alloc	*new;
	t_alloc	*move;
	size_t	size_zone;

	move = (*zone);
	size_zone = sizeof(t_alloc);
	while (move->next != NULL)
		move = move->next;
	new = move + size_zone;
	printf("%d %d\n", TINY, SMALL);
	new->tiny = mmap(NULL, TINY, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	new->small = mmap(NULL, SMALL, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	new->tinynow = new->tiny;
	new->smallnow = new->small;
	new->tinyblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	new->smallblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	new->largeblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	new->nballoctiny = 0;
	new->nballocsmall = 0;
	new->tinysize = 0;
	new->smallsize = 0;
	new->next = NULL;
	move->next = new;
}

int 	control_size(size_t size,size_t size_now, size_t maxsize)
{
	if (size_now + size > maxsize)
	{
		return (0);
	}
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

void	*add_small_alloc(t_alloc **zone, size_t size)
{
	void	*ptr;
	if (control_size(size, (*zone)->smallsize, SMALL))
	{
		ptr = (*zone)->smallnow;
		check_list((*zone)->smallblock, size, ptr);
		(*zone)->smallnow = (*zone)->smallnow + size;
		(*zone)->smallsize += size;
		(*zone)->nballocsmall++;
	}
	return (ptr);
}

void	*add_tiny_alloc(t_alloc **zone, size_t size)
{
	void	*ptr;
	if (control_size(size, (*zone)->tinysize, TINY))
	{
		ptr = (*zone)->tinynow;
		check_list((*zone)->tinyblock, size, ptr);
		(*zone)->tinynow = (*zone)->tinynow + size;
		(*zone)->tinysize += size;
		(*zone)->nballoctiny++;
	}
	return (ptr);
}

void	*select_zone(t_alloc **zone, size_t size)
{
	void *ptr;

	if (size > (SMALL / 100))
	{
		ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		check_list((*zone)->largeblock, size, ptr);
	}
	else if (size < (SMALL / 100) && size > (TINY / 100) && (size + (*zone)->smallsize) < SMALL)
	{
		
		else

	}
	else if (size < (TINY / 100) && (size + (*zone)->tinysize) < TINY)
	{
		
	}
	return (ptr);
}

t_alloc	**init_zone(void)
{
	static t_alloc *zone;

	zone = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

	return (&zone);
}

t_alloc	*init(void)
{
	t_alloc **zone;

	zone = init_zone();
	printf("%d %d\n", TINY, SMALL);
	(*zone)->tiny = mmap(NULL, TINY, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	(*zone)->small = mmap(NULL, SMALL, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
		perror("ERROR:");
	printf("%s\n", "TEST");
	(*zone)->tinynow = (*zone)->tiny;
	(*zone)->smallnow = (*zone)->small;
	(*zone)->tinyblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	(*zone)->smallblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	(*zone)->largeblock = mmap(NULL, 2048, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	perror("ERROR:");
	(*zone)->nballoctiny = 0;
	(*zone)->nballocsmall = 0;
	(*zone)->tinysize = 0;
	(*zone)->smallsize = 0;
	printf("tiny init == %p %p\n", (*zone)->tiny, (*zone)->tinynow);
	printf("small init == %p %p\n", (*zone)->small, (*zone)->smallnow);
	(*zone)->next = NULL;
	return ((*zone));
}

void	*ft_malloc(size_t size)
{
	void		*ptr;
	t_alloc		**zone;
	static int 	first = 0;

	ptr = NULL;
	if (first == 0)
	{
		*zone = init();
		first = 1;
	}
	else
	{
		first++;
	}
	printf("tiny malloc == %p %p\n", (*zone)->tiny, (*zone)->tinynow);
	printf("small malloc == %p %p\n", (*zone)->small, (*zone)->smallnow);
	
	printf("ptr = %p\n", ptr);
	ptr = select_zone(zone, size);
	printf("nb = %d",first);
	print_list((*zone)->tinyblock);
	return (ptr);
}
