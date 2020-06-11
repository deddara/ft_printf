/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:25:14 by deddara           #+#    #+#             */
/*   Updated: 2020/06/11 07:28:13 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int i;
	//int res = ft_printf("%0+*d", -2);
	i = printf("%*s", 32767, "SUKA ROT EVAL IDID NA ");

    printf("%*s", -32, "abc");
    printf("%-*s", -32, "abc");
    printf("%*s", -3, "hello");
    printf("%.*s", -3, "hello");
    printf("%-*.*s", -7, -3, "yolo");
    printf("%*i", -4, 94827);
    printf("%*i", -14, 94827);
    printf("%.*i", -6, -3);
    printf("%0*i", -7, -54);

	printf("\n%d\n", i);
	//int i = 10;
	//if (res == -1)
	//	printf("POSHOL NA HUY");
}
