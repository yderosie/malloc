/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:19:21 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/06 08:02:27 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[j] != '\0')
		j++;
	s1 = (char *)malloc(sizeof(*s1) * (1 * j));
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	if (s1 == NULL)
		return (NULL);
	return (s1);
}
