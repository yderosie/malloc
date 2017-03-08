/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:29:14 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/11 17:22:01 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s4;
	char	*s5;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = (void *)s1;
	s4 = (void *)s2;
	if (s3 == NULL || s4 == NULL)
		return (NULL);
	s5 = (char *)malloc(sizeof(s5) * (1 + ft_strlen(s3) + ft_strlen(s4)));
	if (s5 == NULL)
		return (NULL);
	while (s3[i] != '\0')
		s5[j++] = s3[i++];
	i = 0;
	while (s4[i] != '\0')
		s5[j++] = s4[i++];
	s5[j] = '\0';
	return (s5);
}
