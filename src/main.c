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

#include <stdio.h>

int main()
{
	char *test;
	char *test2;
	char *test3;
	char *test4;
	char *test5;
	char *test6;
	char *test7;
	char *test8;
	char *test9;
	char *test10;
	char *test11;

	test = (char*)ft_malloc(sizeof(char)*10);
	test2 = (char*)ft_malloc(sizeof(char)*20);
	test3 = (char*)ft_malloc(sizeof(char)*30);
	test4 = (char*)ft_malloc(sizeof(char)*50);
	test5 = (char*)ft_malloc(sizeof(char)*60);
	test6 = (char*)ft_malloc(sizeof(char)*70);
	test7 = (char*)ft_malloc(sizeof(char)*4096);
	test8 = (char*)ft_malloc(sizeof(char)*2048);
	test9 = (char*)ft_malloc(sizeof(char)*5);
	test10 = (char*)ft_malloc(sizeof(char)*40);
	test11 = (char*)ft_malloc(sizeof(char)*90);
	if (test == NULL)
		printf("NULL test main = %p\n", test);
	if (test2 == NULL)
		printf("test2 main = %p\n", test2);
	printf("test main = %p %p\n", &test, test);
	printf("test2 main = %p %p\n", &test2, test2);
	test[0] = 't';
	test[1] = 'e';
	test[2] = 's';
	test[3] = 't';
	test[4] = '1';
	test[5] = '\0';
	printf("test main = %p %p %s\n", &test, test, test);
	printf("test2 main = %p %p %s\n", &test2, test2, test2);
	test2[0] = 't';
	test2[1] = 'e';
	test2[2] = 's';
	test2[3] = 't';
	test2[4] = '2';
	test2[5] = '\0';
	test2[6] = 'q';
	test2[7] = '\0';
	printf("test2 main = %p %s\n", &test2, test2);
	printf("test main = %p %p %s\n", &test, test, test);
	ft_free(test);
	ft_free(test8);
	show_alloc_mem();
	return 0;
}
