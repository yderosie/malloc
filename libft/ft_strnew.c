/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:52:14 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/06 08:03:52 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc(sizeof(*s1) * (1 + size));
	if (s1 == NULL)
		return (NULL);
	while (size > 0)
	{
		s1[i] = '\0';
		i++;
		size--;
	}
	s1[i] = '\0';
	return (s1);
}
