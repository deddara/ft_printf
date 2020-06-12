/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 06:10:29 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 03:06:27 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	u_precision_print_handler(t_data *data_list, int numb_len)
{
	while (data_list->precision > numb_len)
	{
		write(1, "0", 1);
		data_list->precision--;
	}
}

static int	u_precision_handler(int res, t_data *data_list, int numb_len)
{
	data_list->len = data_list->precision;
	if (data_list->flags & MINUS_FLAG)
	{
		u_precision_print_handler(data_list, numb_len);
		ft_u_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	u_precision_print_handler(data_list, numb_len);
	ft_u_putnbr(res);
	return (1);
}


int	u_handler(t_data *data_list, va_list ***args)
{
	unsigned int	res;
	unsigned int	numb_len;

	res = va_arg(***args, unsigned int);
	numb_len = unum_len(res);
	data_list->len = numb_len;
	if (data_list->precision == 0 && !res)
	{
		data_list->len = 0;
		space_printer(data_list);
		return (1);
	}
	if ((data_list->precision != -1) && (data_list->precision >(int)numb_len))
		return (u_precision_handler(res, data_list, numb_len));
	if ((data_list->flags & MINUS_FLAG))
	{
		u_precision_print_handler(data_list, numb_len);
		ft_u_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	ft_u_putnbr(res);
	return (1);
}
