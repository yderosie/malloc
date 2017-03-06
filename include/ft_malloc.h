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
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define TINY 4096//2097152
# define SMALL 2*4096//16777216
# define LEN_LIST 4096

typedef struct	s_block
{
	void			*ptr;
	size_t			size;
	int				free;
	int				first;
	struct s_block	*next;
}				t_block;

typedef struct	s_zone
{
	void			*zone;
	void			*zonenow;
	t_block			*zoneblock;
	size_t			nballoczone;
	size_t			zonesize;
	struct s_zone	*next;
}				t_zone;

/*
typedef struct	s_alloc
{
	void			*tiny;
	void			*tinynow;
	void			*small;
	void			*smallnow;
	t_block			*tinyblock;
	t_block			*smallblock;
	t_block			*largeblock;
	int				nballoctiny;
	int				nballocsmall;
	int				tinysize;
	int				smallsize;
	struct s_alloc	*next;
}				t_alloc;*/

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);
t_zone	**init_zone(int i);
void	show_alloc_mem(void);
t_block **init_list_large(void);

#endif