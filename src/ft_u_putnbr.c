/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 06:56:50 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 09:50:32 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

static void		ft_u_recursion(unsigned int n)
{
	char c;

	if (n >= 10)
		ft_u_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_u_putnbr(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_u_recursion(n);
}

static void		ft_u_l_recursion(unsigned long int n)
{
	char c;

	if (n >= 10)
		ft_u_l_recursion(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void			ft_u_l_putnbr(unsigned long int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_u_l_recursion(n);
}
