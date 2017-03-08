/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 02:46:44 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/10 01:50:41 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*tmp;

	lst2 = f(lst);
	tmp = lst2;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (lst2);
}
