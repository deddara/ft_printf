/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 01:57:13 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 01:54:30 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	l_num_len(long int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
int	ll_num_len(long long int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
