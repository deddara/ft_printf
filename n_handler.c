/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:34:40 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 22:55:54 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	n_short_h(va_list ****args, int len, t_data *data_list)
{
	short int	*res;
	signed char	*res1;

	if (data_list->l_specifier & HH_SPEC)
	{
		res1 = va_arg(****args, signed char *);
		res1[0] = (signed char)len;
	}
	else if (data_list->l_specifier & H_SPEC)
	{
		res = va_arg(****args, short int *);
		res[0] = (short int)len;
	}
}

void		n_handler(t_data *data_list, va_list ***args, int len)
{
	int				*res;
	long int		*res1;
	long long int	*res2;

	if (!data_list->l_specifier)
	{
		res = va_arg(***args, int *);
		res[0] = len;
	}
	else if (data_list->l_specifier & LL_SPEC)
	{
		res2 = va_arg(***args, long long int *);
		res2[0] = (long long int)len;
	}
	else if (data_list->l_specifier & L_SPEC)
	{
		res1 = va_arg(***args, long int *);
		res1[0] = (long int)len;
	}
	else
		n_short_h(&args, len, data_list);
}
