/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:44:58 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/20 12:32:41 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	int				i;
	int				k;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	k = 0;
	while (n != 0)
	{
		if (s3[k] != s4[k])
		{
			i = s3[k] - s4[k];
			return (i);
		}
		k++;
		n--;
	}
	return (i);
}
