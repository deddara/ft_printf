/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 23:49:22 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 11:16:59 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

void	ft_lstclear(t_data *data_list)
{
	if (data_list)
	{
		free(data_list);
	}
}
