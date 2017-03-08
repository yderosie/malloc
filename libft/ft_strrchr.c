/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:34:48 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/19 11:09:11 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char			*s1;
	unsigned char	c2;
	int				i;

	c2 = c;
	s1 = (char *)s;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c2)
			return (s1 + (i));
		i--;
	}
	return (NULL);
}
