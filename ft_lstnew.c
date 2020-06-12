/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 21:33:53 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 02:51:57 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

t_data	*ft_lstnew()
{
	t_data *var;

	if(!(var = malloc(sizeof(t_data))))
		return (0);
	var->flags = NO_FLAG;
	var->width = 0;
	var->precision = -1;
	var->l_specifier = NO_SPEC;
	var->type = '\0';
	var->len = 0;
	var->null_str = "(null)";
	var->next = NULL;
	return (var);
}
