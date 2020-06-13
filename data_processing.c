/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 22:12:54 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 13:23:32 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		space_printer(t_data *data_list)
{
	while ((unsigned int)data_list->width > data_list->len)
	{
		if ((data_list->flags & NULL_FLAG) && (data_list->precision) == -1
		&& (data_list->type == 'd' || data_list->type == 'u' ||
		data_list->type == 'x' || data_list->type == '%'
		|| data_list->type == 'X')
		&& !(data_list->flags & MINUS_FLAG))
		{
			write(1, "0", 1);
			data_list->len = data_list->len + 1;
			continue;
		}
		write(1, " ", 1);
		data_list->len = data_list->len + 1;
	}
}

static int	char_handler(t_data *data_list, va_list ***args)
{
	unsigned char res;

	res = va_arg(***args, int);
	data_list->len++;
	if (data_list->flags & MINUS_FLAG)
	{
		write(1, &res, 1);
		space_printer(data_list);
	}
	else
	{
		space_printer(data_list);
		write(1, &res, 1);
	}
	return (1);
}

static int	add_s_dt_prsng(t_data *data_list, va_list **args)
{
	if (data_list->type == 'x' && data_list->l_specifier & LL_SPEC)
		return (x_ll_handler(data_list, &args));
	else if (data_list->type == 'x' && data_list->l_specifier & L_SPEC)
		return (x_l_handler(data_list, &args));
	else if (data_list->type == 'x' && data_list->l_specifier & HH_SPEC)
		return (x_hh_handler(data_list, &args));
	else if (data_list->type == 'x' && data_list->l_specifier & H_SPEC)
		return (x_h_handler(data_list, &args));
	else if (data_list->type == 'X' && data_list->l_specifier & LL_SPEC)
		return (x_grt_ll_handler(data_list, &args));
	else if (data_list->type == 'X' && data_list->l_specifier & L_SPEC)
		return (x_grt_l_handler(data_list, &args));
	else if (data_list->type == 'X' && data_list->l_specifier & HH_SPEC)
		return (x_grt_hh_handler(data_list, &args));
	else if (data_list->type == 'X' && data_list->l_specifier & H_SPEC)
		return (x_grt_h_handler(data_list, &args));
	else
		return (0);
}

static int	specifier_data_processing(t_data *data_list, va_list **args)
{
	if (data_list->type == 'd' && data_list->l_specifier & LL_SPEC)
		return (ll_d_handler(data_list, &args));
	else if (data_list->type == 'd' && data_list->l_specifier & L_SPEC)
		return (l_d_handler(data_list, &args));
	else if (data_list->type == 'd' && data_list->l_specifier & HH_SPEC)
		return (hh_d_handler(data_list, &args));
	else if (data_list->type == 'd' && data_list->l_specifier & H_SPEC)
		return (h_d_handler(data_list, &args));
	else if (data_list->type == 'u' && data_list->l_specifier & LL_SPEC)
		return (u_ll_handler(data_list, &args));
	else if (data_list->type == 'u' && data_list->l_specifier & L_SPEC)
		return (u_l_handler(data_list, &args));
	else if (data_list->type == 'u' && data_list->l_specifier & HH_SPEC)
		return (u_hh_handler(data_list, &args));
	else if (data_list->type == 'u' && data_list->l_specifier & H_SPEC)
		return (u_h_handler(data_list, &args));
	else
		return (add_s_dt_prsng(data_list, args));
	return (0);
}

int			data_processing(t_data *data_list, va_list **args)
{
	if (data_list->type == 'd' && !data_list->l_specifier)
		return (d_handler(data_list, &(args)));
	else if (data_list->type == 'c')
		return (char_handler(data_list, &(args)));
	else if (data_list->type == 's')
		return (string_handler(data_list, &(args)));
	else if (data_list->type == 'x' && !data_list->l_specifier)
		return (x_handler(data_list, &args));
	else if (data_list->type == 'X' && !data_list->l_specifier)
		return (greater_x_handler(data_list, &args));
	else if (data_list->type == 'p')
		return (p_handler(data_list, &args));
	else if (data_list->type == 'u' && !data_list->l_specifier)
		return (u_handler(data_list, &args));
	else if (data_list->type == '%')
		return (percent_handler(data_list));
	else if (data_list->l_specifier)
		return (specifier_data_processing(data_list, args));
	else
		return (1);
}
