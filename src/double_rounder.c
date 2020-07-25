/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rounder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 22:34:17 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 22:49:31 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			double_len(t_data *data_list, double res)
{
	int dec;

	if (res < 0)
		res *= -1;
	dec = unum_ll_len((size_t)res);
	if (data_list->precision != 0 || data_list->flags & HASH_FLAG)
		data_list->len++;
	data_list->len += data_list->precision;
	data_list->len += dec;
}

static double	double_pow(int precision)
{
	double pow;

	pow = 0.5;
	while (precision-- > 0)
		pow *= 0.1;
	return (pow);
}

double			rounder(t_data *data_list, double res)
{
	double	tmp;
	int		i;
	int		sign;

	sign = 1;
	if (res < 0)
		sign = -1;
	tmp = res;
	i = -1;
	while (i < data_list->precision)
	{
		tmp -= (size_t)tmp;
		tmp *= 10;
		i++;
	}
	if ((sign == 1 && tmp < 5.0) || (sign == -1 && tmp >= -5.0))
		return (res);
	else
	{
		tmp = double_pow(data_list->precision);
		res += tmp * sign;
	}
	return (res);
}
