/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:11:17 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/26 16:33:04 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	int i = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	int j = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//	int j = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% \n", 'A', "42", 42, 42, 42, 42, 42);
//	int j = ft_printf("%%%%\n");
	printf("or = %d, my = %d", i, j);
//	printf("ret = %d", j);
//	char a;
//	char *b = &a;
//
//	a = '8';
//	char d= 'a', e = 'b', f = 'c';
//	ft_printf("%c%c%c\n", d, e, f);
//	int	k = ft_printf("test s = %s\n", "ag\0hahg");
//	int j = printf("correct = %s\n", "ag\0hahg");
//	k += ft_printf("test c = %c\n", a);
//	j += printf("correct = %c\n", a);
//	k += ft_printf("test p = %p\n", b);
//	j += printf("correct =%p\n", b);
//	k += ft_printf("test d = %d\n", 15);
//	j += printf("correct = %d\n", 15);
//	k += ft_printf("test i = %i\n", 8964);
//	j += printf("correct = %i\n", 8964);
//	k += ft_printf("test u = %u\n", 2999999999);
//	j += printf("correct = %ld\n", 2999999999);
//	k += ft_printf("test x = %x\n", 1564889);
//	j += printf("correct = %x\n", 1564889);
//	k += ft_printf("test X = %X\n", 1564889);
//	j += printf("correct = %X\n", 1564889);
//	k += ft_printf("test PERCENT = %%\n");
//	j += printf("correct = %%\n");
//	printf("MY returned = %d\n", k);
//	printf("ORIGINAL returned = %d", j);
}