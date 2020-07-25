/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:42:35 by deddara           #+#    #+#             */
/*   Updated: 2020/06/09 20:44:02 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_handler(t_data *data_list)
{
	data_list->len = 1;
	if (data_list->flags & MINUS_FLAG)
	{
		write(1, "%", 1);
		space_printer(data_list);
	}
	else
	{
		space_printer(data_list);
		write(1, "%", 1);
	}
	return (1);
}
