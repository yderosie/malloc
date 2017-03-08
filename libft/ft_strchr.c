/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:11:45 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/18 10:02:15 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	if (c == '\0')
		return (s1 + i);
	return (NULL);
}
