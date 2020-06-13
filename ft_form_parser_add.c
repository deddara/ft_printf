/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_parser_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 09:30:31 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 12:22:25 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_l_specifier_add(const char *str, t_data *data_list)
{
	if ((data_list->l_specifier & L_SPEC))
	{
		data_list->l_specifier = data_list->l_specifier | LL_SPEC;
		str++;
		return ((char*)str);
	}
	else if (!data_list->l_specifier && *str == 'l')
		data_list->l_specifier = data_list->l_specifier | L_SPEC;
	else if ((data_list->l_specifier & H_SPEC))
	{
		data_list->l_specifier = data_list->l_specifier | HH_SPEC;
		str++;
		return ((char*)str);
	}
	else if (!data_list->l_specifier && *str == 'h')
		data_list->l_specifier = data_list->l_specifier | H_SPEC;
	str++;
	return ((char*)str);
}

char		*get_l_specifier(const char *str, t_data *data_list)
{
	while (*str)
	{
		if (*str == 'l' && (!data_list->l_specifier ||
		data_list->l_specifier & L_SPEC))
			str = get_l_specifier_add(str, data_list);
		else if (*str == 'h' && (!data_list->l_specifier ||
		data_list->l_specifier & H_SPEC))
			str = get_l_specifier_add(str, data_list);
		else
			break ;
	}
	return ((char*)str);
}
