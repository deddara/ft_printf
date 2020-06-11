/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 03:36:17 by deddara           #+#    #+#             */
/*   Updated: 2020/06/11 06:57:19 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_recursion(int n)
{
	char c;

	if (n >= 10)
		ft_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "2147483648", 11);
	else if (n == 0)
		write(1, "0", 1);
	else if (n < 0)
	{
		n = n * (-1);
	}
	if (n > 0)
		ft_recursion(n);
}
