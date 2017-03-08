/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:38:03 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/10 03:31:02 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	c;
	char	i;
	size_t	len;
	int		j;

	j = 0;
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!j || ft_strncmp(s1, s2, len) != 0)
		{
			j = 1;
			if ((i = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (i != c)
			{
				if ((i = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
