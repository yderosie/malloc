/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:47:36 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/13 10:41:47 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = dst;
	s2 = (char *)src;
	while (n != 0)
	{
		*s1++ = *s2++;
		n--;
	}
	return (dst);
}
