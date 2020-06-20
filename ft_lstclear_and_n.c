/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_and_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 13:06:19 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 22:49:43 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

void	ft_lstclear_and_n(t_data *data_list, va_list **args, int len)
{
	if (data_list->type == 'n')
		n_handler(data_list, &args, len);
	if (data_list)
	{
		free(data_list);
	}
}
