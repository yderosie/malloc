/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:40:05 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/21 13:38:46 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_traitement(char *s, int j, int k)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			j = (j * 10) + (s[i] - '0');
			if (s[i - 1] == '-')
				k++;
			i++;
		}
		else if (((s[i] == ' ' && j == '\0') || ((s[i] == '-' && j == '\0') &&
					(s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] != '0'))
						|| ((s[i] == '+' && j == '\0') && (s[i + 1] >= '0' &&
							s[i + 1] <= '9')) || ((s[i] >= 9 && s[i] <= 13) &&
								j == '\0')) && (s[i - 1] != '0'))
			i++;
		else
			break ;
	}
	if (k > 0)
		j = j * (-1);
	return (j);
}

int				ft_atoi(char const *str)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	s = (char*)str;
	j = ft_traitement(s, i, k);
	return (j);
}
