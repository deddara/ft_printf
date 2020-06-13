/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:34:40 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 15:09:31 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_handler(t_data *data_list, va_list ***args, int len)
{
	int *res;
	int j[0];
	if(!data_list->l_specifier)
	{
		res = va_arg(***args, int *);
		res = j;
		*res = len;
		printf("==%d", j[0]);
	}
}
