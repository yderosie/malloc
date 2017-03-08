/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:19:44 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/18 10:56:33 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	s1 = (void *)s;
	s2 = (char *)malloc(sizeof(*s2) * (1 + ft_strlen(s1)));
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		return (ft_strtrim(s + 1));
	while (s[i] != '\0')
		s2[j++] = s1[i++];
	while (s2[j - 1] == ' ' || s2[j - 1] == '\n' || s2[j - 1] == '\t')
	{
		s2[j - 1] = '\0';
		j--;
	}
	if (s2 == NULL)
		return (NULL);
	return (s2);
}
