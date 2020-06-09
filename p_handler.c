/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:20:00 by deddara           #+#    #+#             */
/*   Updated: 2020/06/10 00:13:29 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	p_precision_print_handler(t_data *data_list, int numb_len)
{
	write(1, "0x", 2);
	while (data_list->precision > numb_len)
	{
		write(1, "0", 1);
		data_list->precision--;
	}
}

int	p_simple_handler(char *hex, t_data *data_list, int numb_len)
{
	space_printer(data_list);
	p_precision_print_handler(data_list, numb_len);
	ft_putstr(hex);
	return (1);
}

static void	converter(char *hexadecimal,size_t res)
{
	int j;
	int i;
	size_t backup;
	char		*reverse;

	if (!(reverse = (char *)malloc(sizeof(int) * 100)))
		return ;
	j = 0;
	i = 0;
	while (res != 0)
	{
		backup = res % 16;
		if (backup < 10)
			reverse[j++] = 48 + backup;
		else
			reverse[j++] = 87 + backup;
		res /= 16;
	}
	hexadecimal[j] = 0;
	j--;
	while (j >= 0)
		hexadecimal[i++] = reverse[j--];
	free (reverse);
}

int p_precision_handler(char *hex,t_data *data_list, int numb_len)
{
	data_list->len = data_list->precision + 2;
	if (data_list->flags & MINUS_FLAG)
	{
		p_precision_print_handler(data_list, numb_len);
		if (!(numb_len == 0 && data_list->precision >= 0))
			ft_putstr(hex);
		space_printer(data_list);
		return (1);
	}
	space_printer(data_list);
	p_precision_print_handler(data_list, numb_len);
	if (!(numb_len == 0 && data_list->precision >= 0))
		ft_putstr(hex);
	return (1);
}

int	p_handler(t_data *data_list, va_list ***args)
{
	size_t	res;
	char			hexadecimal[100];
	int				numb_len;

	res = va_arg(***args, size_t);
	converter(hexadecimal, res);
	numb_len = ft_strlen(hexadecimal);
	data_list->len = numb_len + 2;
	if (((data_list->precision != -1) && data_list->precision > numb_len)
	|| (data_list->precision != -1 && numb_len == 0))
		return (p_precision_handler(hexadecimal, data_list, numb_len));
	if ((data_list->flags & MINUS_FLAG))
	{
		p_precision_print_handler(data_list, numb_len);
		ft_putstr(hexadecimal);
		space_printer(data_list);
		return (1);
	}
	return (p_simple_handler(hexadecimal, data_list, numb_len));
}
