/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:39 by yderosie          #+#    #+#             */
/*   Updated: 2017/03/10 16:34:43 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static unsigned int	count_c_hexa(unsigned long long i)
{
	unsigned long long	j;
	unsigned long long	k;

	j = 0;
	while (i >= 16)
	{
		k = i;
		i = i / 16;
		k = (k % 16);
		j++;
	}
	j += 2;
	return (j);
}

static char			*ft_inverse(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = ft_strlen(s) - 1;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (j >= 0)
	{
		s2[i] = s[j];
		i++;
		j--;
	}
	s2[i] = '\0';
	return (s2);
}

static char			if_forest_hexa(unsigned int k)
{
	if (k < 10)
		return (k + '0');
	else if (k == 10)
		return ('a');
	else if (k == 11)
		return ('b');
	else if (k == 12)
		return ('c');
	else if (k == 13)
		return ('d');
	else if (k == 14)
		return ('e');
	else
		return ('f');
}

char			*conv_hexa(unsigned long long j)
{
	char				*s1;
	int					i;
	unsigned long long	k;
	char				*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * count_c_hexa(j));
	ft_bzero(s1, count_c_hexa(j));
	while (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(j);
	s2 = ft_inverse(s1);
	free(s1);
	return (s2);
}