/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_hh_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:09:49 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 05:44:39 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_precision_handler(unsigned char res, t_data *data_list, int numb_len)
{
	data_list->len = data_list->precision;
	if (data_list->flags & MINUS_FLAG)
	{
		u_precision_print_handler(data_list, numb_len);
		ft_u_hh_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	u_precision_print_handler(data_list, numb_len);
	ft_u_hh_putnbr(res);
	return (1);
}


int	u_hh_handler(t_data *data_list, va_list ***args)
{
	unsigned char	res;
	unsigned int	numb_len;

	res = va_arg(***args, int);
	numb_len = unum_hh_len(res);
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
		ft_u_hh_putnbr(res);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	ft_u_hh_putnbr(res);
	return (1);
}
