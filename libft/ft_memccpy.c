/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:15:09 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/10 03:34:09 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char	*s1;
	char			*s2;
	int				i;

	i = 0;
	s1 = dst;
	s2 = (char *)src;
	while (n > 0)
	{
		s1[i] = s2[i];
		if (s2[i] == c)
		{
			i = i + 1;
			return ((void *)s1 + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
