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

	test = (char*)ft_malloc(sizeof(char)*10);
	test2 = (char*)ft_malloc(sizeof(char)*20);
	test3 = (char*)ft_malloc(sizeof(char)*30);
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
	ft_free(test2);
	return 0;
}
