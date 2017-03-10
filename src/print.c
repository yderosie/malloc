/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:39:52 by yderosie          #+#    #+#             */
/*   Updated: 2017/03/10 15:39:53 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		ft_putnbr_u(unsigned long long n)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(48 + n);
}

static void		parcour_block(t_block *move, unsigned long long *total_size)
{
	while (move != NULL)
	{
		if (move->free == 0)
		{
			ft_putstr("0x");
			ft_putstr(conv_hexa((unsigned long long)move->ptr));
			ft_putstr(" - 0x");
			ft_putstr(conv_hexa(
				(unsigned long long)move->ptr + move->size - 1));
			ft_putstr(" : ");
			ft_putnbr_u(move->size);
			ft_putstr(" octects\n");
			*total_size += move->size;
		}
		move = move->next;
	}
}

static void		select_zone(t_zone **zone, int i)
{
	if (i == 1)
	{
		ft_putstr("TINY : ");
		ft_putstr("0x");
	}
	if (i == 2)
	{
		ft_putstr("SMALL : ");
		ft_putstr("0x");
	}
		ft_putstr(conv_hexa((unsigned long long)(*zone)->zone));
		ft_putchar('\n');
}

void			show_alloc_mem(void)
{
	t_zone				**zonetiny;
	t_zone				**zonesmall;
	t_block				*move;
	unsigned long long	total_size;

	zonetiny = init_zone_tiny();
	zonesmall = init_zone_small();
	total_size = 0;
	move = (*zonetiny)->zoneblock;
	select_zone(zonetiny, 1);
	parcour_block(move, &total_size);
	move = (*zonesmall)->zoneblock;
	select_zone(zonesmall, 2);
	parcour_block(move, &total_size);
	move = *(init_list_large());
	ft_putstr("LARGE : ");
	ft_putstr("0x");
	ft_putstr(conv_hexa((unsigned long long)move->ptr));
	ft_putchar('\n');
	parcour_block(move, &total_size);
	ft_putstr("Total : ");
	ft_putnbr_u(total_size);
	ft_putstr(" octects\n");
}
