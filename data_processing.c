/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 22:12:54 by deddara           #+#    #+#             */
/*   Updated: 2020/06/11 22:24:04 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void space_printer(t_data *data_list)
{
	while ((unsigned int)data_list->width > data_list->len)
	{
		if ((data_list->flags & NULL_FLAG) && (data_list->precision) == -1
		&& (data_list->type == 'd' || data_list->type == 'u' || data_list->type == 'x'
		|| data_list->type == '%' || data_list->type == 'X')
		&& !(data_list->flags & MINUS_FLAG))
		{
			write(1, "0", 1);
			data_list->len = data_list->len + 1;
			continue;
		}
		write (1, " ", 1);
		data_list->len = data_list->len + 1;
	}
}

int char_handler(t_data *data_list, va_list ***args)
{
	unsigned char res;

	res = va_arg(***args, int);
	data_list->len++;
	if (data_list->flags & MINUS_FLAG)
	{
		write (1, &res, 1);
		space_printer(data_list);
	}
	else
	{
		space_printer(data_list);
		write(1,&res, 1);
	}
	return (1);
}

int data_processing(t_data *data_list, va_list **args)
{
	if (data_list->type == 'd')
		return (d_handler(data_list, &(args)));
	else if(data_list->type == 'c')
		return (char_handler(data_list, &(args)));
	else if (data_list->type == 's')
		return(string_handler(data_list, &(args)));
	else if (data_list->type == 'x')
		return(x_handler(data_list, &args));
	else if(data_list->type == 'X')
		return (greater_x_handler(data_list, &args));
	else if (data_list->type == 'p')
		return (p_handler(data_list, &args));
	else if (data_list->type == 'u')
		return (u_handler(data_list, &args));
	else if (data_list->type == '%')
		return (percent_handler(data_list));
	else
		return (0);
}
