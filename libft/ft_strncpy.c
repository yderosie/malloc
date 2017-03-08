/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:05:44 by yderosie          #+#    #+#             */
/*   Updated: 2015/05/18 16:20:29 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	int		i;

	i = -1;
	while (src[++i] != '\0' && n > (size_t)i)
		dst[i] = src[i];
	while (n >= (size_t)i)
		dst[i++] = '\0';
	return (dst);
}
