/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 10:40:23 by yderosie          #+#    #+#             */
/*   Updated: 2014/12/17 10:50:49 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *ptr, size_t size)
{
	char *s1;

	s1 = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + size + 1));
	if (s1 == NULL)
		return (NULL);
	s1 = ft_strcpy(s1, ptr);
	free(ptr);
	return (s1);
}
