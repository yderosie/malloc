/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:37:06 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/27 16:37:08 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int main()
{
	char *test;
	char *test2;

	test = (char*)ft_malloc(sizeof(char)*10);
	test2 = (char*)ft_malloc(sizeof(char)*10);
	if (test == NULL)
		printf("test = %p\n", test);
	if (test2 == NULL)
		printf("test2 = %p\n", test2);
	printf("test = %p\n", &test);
	printf("test2 = %p\n", &test2);
	//return 0;
	test[0] = 'q';
	test = "a\0";
	test2 = "testa\0";
	test2[6] = 'q';
	test2[7] = '\0';
	printf("test = %p\n", &test);
	printf("test2 = %p %s\n", &test2, test2);
	return 0;
}
