/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:53:27 by yderosie          #+#    #+#             */
/*   Updated: 2014/12/28 17:42:29 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	char		*s1;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s1 = (char *)s;
	while (n != 0)
	{
		if (s1[i] == (char)c)
			return (s1 + i);
		i++;
		n--;
	}
	return (NULL);
}
