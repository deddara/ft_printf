/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:25:14 by deddara           #+#    #+#             */
/*   Updated: 2020/06/08 07:11:34 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int i;
	char *s = "yep hello ";
	//int res = ft_printf("%0+*d", -2);
	i = printf("%#X", -434234);

	printf("\n%d\n", i);
	//int i = 10;
	//if (res == -1)
	//	printf("POSHOL NA HUY");
}
