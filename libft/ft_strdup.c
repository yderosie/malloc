/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:31:12 by yderosie          #+#    #+#             */
/*   Updated: 2015/03/20 15:09:06 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *s1)
{
	char	*s;
	char	*s2;
	int		i;

	i = 0;
	s = (void *)s1;
	s2 = (char *)malloc(sizeof(*s2) * (1 + ft_strlen(s)));
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	if (s2 == NULL)
		return (NULL);
	return (s2);
}
