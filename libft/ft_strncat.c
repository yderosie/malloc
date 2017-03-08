/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:00:43 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/10 09:19:24 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	int		i;
	int		j;
	char	*s;

	s = (void *)s2;
	i = ft_strlen(s1);
	j = 0;
	while (n != 0 && s[j] != '\0')
	{
		s1[i++] = s[j++];
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
