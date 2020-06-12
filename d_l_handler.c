/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_l_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:48:11 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 08:17:41 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_precision_print_handler(long int res, t_data *data_list, int numb_len)
{
	if (res < 0)
		write(1, "-", 1);
	else if (res >= 0 && data_list->flags & PLUS_FLAG)
		write(1, "+", 1);
	else if (data_list->flags & SPACE_FLAG && res >= 0)
		write(1, " ", 1);
	while (data_list->precision > numb_len)
	{
		write(1, "0", 1);
		data_list->precision--;
	}
}

static int	d_simple_handler(long int res, t_data *data_list, int numb_len)
{
	if (data_list->flags & NULL_FLAG && data_list->precision == -1)
	{
		d_precision_print_handler(res, data_list, numb_len);
		space_printer(data_list);
		if (!(data_list->precision == 0 && !res))
			ft_l_putnbr(res);
	}
	else
	{
		space_printer(data_list);
		d_precision_print_handler(res, data_list, numb_len);
		if (!(data_list->precision == 0 && !res))
			ft_l_putnbr(res);
	}
	return (1);
}

static void	d_flagcheck(long int res, t_data *data_list)
{
	if (res < 0)
	{
		data_list->len++;
	}
	else if (res >= 0 && data_list->flags & PLUS_FLAG)
	{
		data_list->len++;
	}
	else if (data_list->flags & SPACE_FLAG && res >= 0)
	{
		data_list->len++;
	}
}

static int	d_precision_handler(long int res, t_data *data_list, int numb_len)
{
	data_list->len = data_list->precision;
	if (data_list->flags & MINUS_FLAG)
	{
		d_flagcheck(res, data_list);
		d_precision_print_handler(res, data_list, numb_len);
		if (!(data_list->precision == 0 && !res))
			ft_l_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	d_flagcheck(res, data_list);
	space_printer(data_list);
	d_precision_print_handler(res, data_list, numb_len);
	if (!(data_list->precision == 0 && !res))
		ft_l_putnbr(res);
	return (1);
}

int			l_d_handler(t_data *data_list, va_list ***args)
{
	long int	res;
	int			numb_len;

	res = va_arg(***args, long int);
	numb_len = l_num_len(res);
	if(res == 0 && data_list->precision == 0)
		numb_len = 0;
	data_list->len = numb_len;
	d_flagcheck(res, data_list);
	if ((data_list->precision != -1) && (data_list->precision > numb_len))
		return (d_precision_handler(res, data_list, numb_len));
	if ((data_list->flags & MINUS_FLAG))
	{
		d_precision_print_handler(res, data_list, numb_len);
		if (!(data_list->precision == 0 && !res))
			ft_l_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	return (d_simple_handler(res, data_list, numb_len));
}
