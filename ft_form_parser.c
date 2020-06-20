/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 21:33:20 by deddara           #+#    #+#             */
/*   Updated: 2020/06/20 22:59:03 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_flags(const char *str, t_data *data_list)
{
	while (*str)
	{
		if (*str == '0')
			data_list->flags = data_list->flags | NULL_FLAG;
		else if (*str == '-')
			data_list->flags = data_list->flags | MINUS_FLAG;
		else if (*str == '+')
			data_list->flags = data_list->flags | PLUS_FLAG;
		else if (*str == '#')
			data_list->flags = data_list->flags | HASH_FLAG;
		else if (*str == ' ')
			data_list->flags = data_list->flags | SPACE_FLAG;
		else
			break ;
		str++;
	}
	return ((char*)str);
}

static char	*get_width(const char *str, va_list *args, t_data *data_list)
{
	data_list->digit = 0;
	while (*str)
	{
		if (*str == 42 && data_list->digit == 0)
		{
			data_list->width = va_arg(*args, int);
			str++;
			if (data_list->width < 0)
			{
				data_list->width = data_list->width * (-1);
				data_list->flags = data_list->flags | MINUS_FLAG;
			}
			return ((char*)str);
		}
		else if (ft_isdigit(*str))
		{
			data_list->width = data_list->width * 10 + (*str - '0');
			data_list->digit++;
		}
		else
			break ;
		str++;
	}
	return ((char *)str);
}

static char	*get_precision(const char *str, va_list *args, t_data *data_list)
{
	data_list->digit = 0;
	if (*str == '.')
	{
		str++;
		data_list->precision = 0;
		while (*str)
		{
			if (*str == '*' && data_list->digit == 0)
			{
				data_list->precision = va_arg(*args, int);
				str++;
				return ((char *)str);
			}
			else if (ft_isdigit(*str))
			{
				data_list->precision = data_list->precision * 10 + (*str - '0');
				data_list->digit++;
			}
			else
				break ;
			str++;
		}
	}
	return ((char *)str);
}

static int	get_type(const char *str, t_data *data_list)
{
	if (*str == 'c')
		data_list->type = 'c';
	else if (*str == 's')
		data_list->type = 's';
	else if (*str == 'p')
		data_list->type = 'p';
	else if (*str == 'd' || *str == 'i')
		data_list->type = 'd';
	else if (*str == 'u')
		data_list->type = 'u';
	else if (*str == 'x')
		data_list->type = 'x';
	else if (*str == 'X')
		data_list->type = 'X';
	else if (*str == '%')
		data_list->type = '%';
	else if (*str == 'n')
		data_list->type = 'n';
	else if (*str == 'f')
		data_list->type = 'f';
	else
		return (0);
	return (1);
}

char		*form_parser(const char *str, va_list *args, int *count)
{
	t_data	*data_list;

	data_list = ft_lstnew();
	str++;
	str = get_flags(str, data_list);
	str = get_width(str, args, data_list);
	str = get_precision(str, args, data_list);
	str = get_l_specifier(str, data_list);
	if (!*str)
	{
		*count = -2;
		ft_lstclear(data_list);
		return (NULL);
	}
	if (!(get_type(str, data_list)))
	{
		write(1, "%", 1);
		*count += 1;
		return (NULL);
	}
	if (!(data_processing(data_list, &(args))))
		return (NULL);
	*count += data_list->len;
	ft_lstclear_and_n(data_list, &(args), *count);
	return ((char*)str);
}
