/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:35:35 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/15 10:35:59 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int		i;
	int		j;

	j = 0;
	i = len;
	s1 = dst;
	s2 = (void *)src;
	s3 = (char *)malloc(sizeof(*s3) * (1 + len));
	while (len-- > 0)
	{
		s3[j] = s2[j];
		j++;
	}
	j = 0;
	while (i-- > 0)
	{
		s1[j] = s3[j];
		j++;
	}
	return (dst);
}
