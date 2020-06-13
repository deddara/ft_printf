/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 07:56:51 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 12:14:17 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_ll_recursion(long long int n)
{
	char c;

	if (n >= 10)
		ft_ll_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_ll_putnbr(long long int n)
{
	if (n == 0)
		write(1, "0", 1);
	else if (n < 0)
	{
		n = n * (-1);
	}
	if (n > 0)
		ft_ll_recursion(n);
}

static void		ft_hh_recursion(signed char n)
{
	char c;

	if (n >= 10)
		ft_hh_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_hh_putnbr(signed char n)
{
	if (n == 0)
		write(1, "0", 1);
	else if (n == -128)
	{
		write(1, "128", 3);
		return ;
	}
	else if (n < 0)
	{
		n = n * (-1);
	}
	if (n > 0)
		ft_hh_recursion(n);
}
