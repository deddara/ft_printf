/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_nan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 22:31:21 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 22:32:12 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int nan_inf(double res, t_data *data_list)
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
