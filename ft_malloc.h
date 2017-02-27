/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:46:05 by yderosie          #+#    #+#             */
/*   Updated: 2016/12/20 15:46:06 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_zone_alloc
{
	void	*tiny;
	void	*tinynow;
	void	*small;
	void	*smallnow;
	int		nballoctiny;
	int		nballocsmall;
	int		tinysize;
	int		smallsize;
}				t_zone_alloc;

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);

#endif