/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:25:14 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 18:28:08 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main()
{
	int i;
	double k;

	*((unsigned long *)(&k)) = DBL_PZERO;
	//int res = ft_printf("%0+*d", -2);
	i = ft_printf("%6f", k);

	printf("\n%d\n", i);
	//int i = 10;
	//if (res == -1)
	//	printf("POSHOL NA HUY");
}
