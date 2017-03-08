/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:10:33 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/17 14:12:14 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	int		i;
	char	*s;

	s = (char *)s1;
	i = 0;
	while (s2[i] != '\0')
	{
		if (s[i] == '\0')
			return (NULL);
		if (s2[i] != s[i])
			return (ft_strstr(s + 1, s2));
		i++;
	}
	return (s);
}
