/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:27:11 by ginobile          #+#    #+#             */
/*   Updated: 2025/02/17 18:27:45 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	original(void);

int	main(void)
{
	ft_printf("\e[91mTHESE ARE BROKEN TESTS\n\e[0m");
	ft_printf("[%-s]\n", NULL);
	ft_printf("[%23s]\n", NULL);
	ft_printf("[%s]\n", NULL);
	ft_printf("[hello, %s.]\n", NULL);
	ft_printf("[%s]\n", NULL);
	ft_printf("[%32s]\n", NULL);
	ft_printf("[%2s]\n", NULL);
	ft_printf("[%-32s]\n", NULL);
	ft_printf("[%-16s]\n", NULL);
	ft_printf("[%-3s]\n", NULL);
	ft_printf("[%.09s]\n", NULL);
	ft_printf("[%3.6s]\n", NULL);
	ft_printf("[%20.6s]\n", NULL);
	ft_printf("[%-3.8s]\n", NULL);
	ft_printf("[%-10.8s]\n", NULL);
	ft_printf("[%08.5u]\n", 34);
	ft_printf("[%08.5u]\n", 0);
	ft_printf("[%08.3u]\n", 8375);
	ft_printf("[%08.5x]\n", 34);
	ft_printf("[%08.5x]\n", 0);
	ft_printf("----------------\n");
	original();
}

void	original(void)
{
	printf("THAT SHOULD'VE BEEN LIKE THIS:\n");
	printf("[%-s]\n", NULL);
	printf("[%23s]\n", NULL);
	printf("[%s]\n", NULL);
	printf("[hello, %s.]\n", NULL);
	printf("[%s]\n", NULL);
	printf("[%32s]\n", NULL);
	printf("[%2s]\n", NULL);
	printf("[%-32s]\n", NULL);
	printf("[%-16s]\n", NULL);
	printf("[%-3s]\n", NULL);
	printf("[%.09s]\n", NULL);
	printf("[%3.6s]\n", NULL);
	printf("[%20.6s]\n", NULL);
	printf("[%-3.8s]\n", NULL);
	printf("[%-10.8s]\n", NULL);
	printf("[%08.5u]\n", 34);
	printf("[%08.5u]\n", 0);
	printf("[%08.3u]\n", 8375);
	printf("[%08.5x]\n", 34);
	printf("[%08.5x]\n", 0);
	printf("----------------\n");
}

//int main(void)
//{
//    /* Test base */
//    ft_printf("----- Test Base -----\n");
//    ft_printf("Char: %5%\n");
//    ft_printf("String: %s\n", "Hello, 42!");
//    ft_printf("Decimal: %d\n", -42);
//    ft_printf("Unsigned: %u\n", 4294967295U);
//    ft_printf("Hexadecimal (lowercase, hash): %#x\n", 255);
//    ft_printf("Hexadecimal (uppercase, hash): %#X\n", 255);
//    ft_printf("Pointer: %p\n", (void *)&main);
//    ft_printf("Percent: %%\n");

//    /* Test per width e precisione sulle stringhe */
//    ft_printf("\n----- Test String (width & precision) -----\n");
//    ft_printf("Width (string): |%10s|\n", "Hello");
//    ft_printf("Precision (string): |%.3s|\n", "Hello");
//    ft_printf("Width & Precision (string): |%10.3s|\n", "Hello, world!");

//    /* Test per width e precisione sui numeri */
//    ft_printf("\n----- Test Numeri (width, precision, flags) -----\n");
//    ft_printf("Width (decimal): |%10d|\n", 42);
//    ft_printf("Zero padded (decimal): |%010d|\n", 42);
//    ft_printf("Precision (decimal): |%.5d|\n", 42);
//    ft_printf("Width & Precision (decimal): |%10.5d|\n", 42);
//    ft_printf("Left aligned (decimal): |%-10d|\n", 42);
//    ft_printf("Plus flag (decimal): |%+d|\n", 42);
//    ft_printf("Space flag (decimal): |% d|\n", 42);

//    /* Test con numeri negativi */
//    ft_printf("\n----- Test Numeri Negativi -----\n");
//    ft_printf("Negative number: |%d|\n", -123);
//    ft_printf("Zero padded negative: |%010d|\n", -123);

//    /* Test su numeri unsigned e esadecimali */
//    ft_printf("\n----- Test Unsigned & Hex -----\n");
//    ft_printf("Width & Precision (unsigned): |%10.5u|\n", 123);
//    ft_printf("Width (hex, lowercase): |%10x|\n", 123);
//    ft_printf("Left aligned hex (uppercase): |%-10X|\n", 123);

///* Test printf base */
//    printf("----- Test Base -----\n");
//    printf("Char: %c\n", 'A');
//    printf("String: %s\n", "Hello, 42!");
//    printf("Decimal: %d\n", -42);
//    printf("Unsigned: %u\n", 4294967295U);
//    printf("Hexadecimal (lowercase, hash): %#x\n", 255);
//    printf("Hexadecimal (uppercase, hash): %#X\n", 255);
//    printf("Pointer: %p\n", (void *)&main);
//    printf("Percent: %%\n");

//    /* Test printf per width e precisione sulle stringhe */
//    printf("\n----- Test String (width & precision) -----\n");
//    printf("Width (string): |%10s|\n", "Hello");
//    printf("Precision (string): |%.3s|\n", "Hello");
//    printf("Width & Precision (string): |%10.3s|\n", "Hello, world!");

//    /* Test printf per width e precisione sui numeri */
//    printf("\n----- Test Numeri (width, precision, flags) -----\n");
//    printf("Width (decimal): |%10d|\n", 42);
//    printf("Zero padded (decimal): |%010d|\n", 42);
//    printf("Precision (decimal): |%.5d|\n", 42);
//    printf("Width & Precision (decimal): |%10.5d|\n", 42);
//    printf("Left aligned (decimal): |%-10d|\n", 42);
//    printf("Plus flag (decimal): |%+d|\n", 42);
//    printf("Space flag (decimal): |% d|\n", 42);

//    /* Test printf con numeri negativi */
//    printf("\n----- Test Numeri Negativi -----\n");
//    printf("Negative number: |%d|\n", -123);
//    printf("Zero padded negative: |%010d|\n", -123);

//    /* Test printf su numeri unsigned e esadecimali */
//    printf("\n----- Test Unsigned & Hex -----\n");
//    printf("Width & Precision (unsigned): |%10.5u|\n", 123);
//    printf("Width (hex, lowercase): |%10x|\n", 123);
//    printf("Left aligned hex (uppercase): |%-10X|\n", 123);

//    return (0);
//}