/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:41:17 by yderosie          #+#    #+#             */
/*   Updated: 2016/12/20 15:41:18 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (ptr == NULL)
		return (ptr);
	new = ft_malloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr));
	ft_free(ptr);
	return (new);
}