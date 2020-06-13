/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_ll_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:51:29 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 05:43:17 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_u_ll_recursion(size_t n)
{
	char c;

	if (n >= 10)
		ft_u_ll_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_u_ll_putnbr(size_t n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_u_ll_recursion(n);
}

static void		ft_u_hh_recursion(unsigned char n)
{
	char c;

	if (n >= 10)
		ft_u_hh_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_u_hh_putnbr(unsigned char n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_u_hh_recursion(n);
}
