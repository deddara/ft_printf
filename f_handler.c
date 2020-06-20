/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:46:27 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 18:28:55 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void f_flag_print(t_data *data_list, double res)
{
	double inf;
	double n_inf;
	*((unsigned long *)(&inf)) = DBL_INF;
	*((unsigned long *)(&n_inf)) = DBL_NINF;
	if (res < 0 || res == n_inf || ((1.0 / res) == n_inf))
		write(1, "-", 1);
	else if ((res >= 0 && data_list->flags & PLUS_FLAG) ||
	(data_list->flags & PLUS_FLAG && res == inf) || (!(res > 0.0 || res < 1.0) && data_list->flags & PLUS_FLAG ))
		write(1, "+", 1);
	else if ((data_list->flags & SPACE_FLAG && res >= 0) ||
	(data_list->flags & SPACE_FLAG && res == inf) || (!(res > 0.0 || res < 1.0) && data_list->flags & SPACE_FLAG ))
		write(1, " ", 1);
}
static void f_flag_check(t_data *data_list, double res)
{
	double inf;
	double n_inf;
	*((unsigned long *)(&inf)) = DBL_INF;
	*((unsigned long *)(&n_inf)) = DBL_NINF;
	if (res < 0 || res == n_inf || ((1.0 / res) == n_inf))
		data_list->len++;
	else if ((res >= 0 && data_list->flags & PLUS_FLAG) ||
	(data_list->flags & PLUS_FLAG && res == inf) || (!(res > 0.0 || res < 1.0) && data_list->flags & PLUS_FLAG ))
		data_list->len++;
	else if ((data_list->flags & SPACE_FLAG && res >= 0) ||
	(data_list->flags & SPACE_FLAG && res == inf) || (!(res > 0.0 || res < 1.0) && data_list->flags & SPACE_FLAG))
		data_list->len++;
}

static int inf_h(t_data *data_list, double res)
{
	data_list->len += 3;
	data_list->flags = data_list->flags & 0b11111110;
	if (data_list->flags & MINUS_FLAG)
	{
		f_flag_print(data_list, res);
		write(1, "inf", 3);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	f_flag_print(data_list, res);
	write(1, "inf", 3);
	return (1);
}
static int nan_h(t_data *data_list, double res)
{
	data_list->len += 3;
	data_list->flags = data_list->flags & 0b11111110;
	if (data_list->flags & MINUS_FLAG)
	{
		f_flag_print(data_list, res);
		write(1, "nan", 3);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	f_flag_print(data_list, res);
	write(1, "nan", 3);
	return (1);
}

static int nan_inf(double res, t_data *data_list)
{
	double spcl;

	*((unsigned long *)(&spcl)) = DBL_INF;
	if(res == spcl)
		return (inf_h(data_list, res));
	*((unsigned long *)(&spcl)) = DBL_NINF;
	if(res == spcl)
		return (inf_h(data_list, res));
	if (!(res > 0.0 || res < 1.0))
		return (nan_h(data_list, res));
	return (0);
}

static void double_len(t_data *data_list, double res)
{
	int dec;

	if (res < 0)
		res *= -1;
	dec = unum_ll_len((size_t)res);
	if (data_list->precision != 0 || data_list->flags & HASH_FLAG)
		data_list->len ++;
	data_list->len += data_list->precision;
	data_list->len += dec;
}

static void put_double(t_data *data_list, double res)
{
	int i;
	char rem;

	if (res < 0)
		res *= -1;
	ft_u_ll_putnbr((size_t)res);
	if (data_list->precision != 0 || data_list->flags & HASH_FLAG)
		write(1, ".", 1);
	res = res - (size_t)res;
	i = 0;
	while (i < data_list->precision)
	{
		res *= 10;
		rem = (char)res % 10 + '0';
		write(1, &rem, 1);
		res -= (char)res;
		i++;
	}
}

static int	put_double_add(double res, t_data *data_list)
{
	if (data_list->flags & NULL_FLAG)
	{
		f_flag_print(data_list, res);
		space_printer(data_list);
		put_double(data_list, res);

	}
	else
	{
		space_printer(data_list);
		f_flag_print(data_list, res);
		put_double(data_list, res);
	}
	return (1);
}

static double double_pow(int precision)
{
	double pow;
	pow = 0.5;
	while (precision-- > 0)
		pow *= 0.1;
	return (pow);
}

static double rounder(t_data *data_list, double res)
{
	double tmp;
	int i;
	int sign;

	sign = 1;
	if (res < 0)
		sign = -1;
	tmp = res;
	i = -1;
	while (i < data_list->precision)
	{
		tmp -=(size_t)tmp;
		tmp *= 10;
		++i;
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

int f_handler(t_data *data_list, va_list ***args)
{
	double res;

	res = va_arg(***args, double);
	f_flag_check(data_list, res);
	if (nan_inf(res, data_list))
		return (1);
	if(data_list->precision == -1)
		data_list->precision = 6;
	res = rounder(data_list, res);
	double_len(data_list, res);
	if ((data_list->flags & MINUS_FLAG))
	{
		f_flag_print(data_list, res);
		put_double(data_list, res);
		space_printer(data_list);
		return (1);
	}
	return (put_double_add(res, data_list));
}
