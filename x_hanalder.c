/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hanalder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 04:35:41 by deddara           #+#    #+#             */
/*   Updated: 2020/06/08 06:34:43 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_check(t_data *data_list)
{
	if (data_list->flags & HASH_FLAG)
		data_list->len += 2;
}

static void	x_precision_print_handler(t_data *data_list, int numb_len)
{
	if (data_list->flags & HASH_FLAG && data_list->type == 'x')
		write(1, "0x", 2);
	else if (data_list->flags & HASH_FLAG && data_list->type == 'X')
		write(1, "0X", 2);
	while (data_list->precision > numb_len)
	{
		write(1, "0", 1);
		data_list->precision--;
	}
}

int	x_simple_handler(char *hex, t_data *data_list, int numb_len)
{
	if (data_list->flags & NULL_FLAG)
	{
		x_precision_print_handler(data_list, numb_len);
		space_printer(data_list);
		ft_putstr(hex);
	}
	else
	{
		space_printer(data_list);
		x_precision_print_handler(data_list, numb_len);
		ft_putstr(hex);
	}
	return (1);
}

static void	converter(char *hexadecimal,unsigned int res)
{
	int j;
	int i;
	unsigned int backup;
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

int x_precision_handler(char *hex,t_data *data_list, int numb_len)
{
	data_list->len = data_list->precision;
	if (data_list->flags & MINUS_FLAG)
	{
		x_precision_print_handler(data_list, numb_len);
		hash_check(data_list);
		ft_putstr(hex);
		space_printer(data_list);
		return (1);
	}
	hash_check(data_list);
	space_printer(data_list);
	x_precision_print_handler(data_list, numb_len);
	ft_putstr(hex);
	return (1);
}

int	x_handler(t_data *data_list, va_list ***args)
{
	unsigned int	res;
	char			hexadecimal[100];
	int				numb_len;

	res = va_arg(***args, unsigned int);
	converter(hexadecimal, res);
	numb_len = ft_strlen(hexadecimal);
	data_list->len = numb_len;
	if ((data_list->precision != -1) && data_list->precision > numb_len)
		return (x_precision_handler(hexadecimal, data_list, numb_len));
	hash_check(data_list);
	if ((data_list->flags & MINUS_FLAG))
	{
		x_precision_print_handler(data_list, numb_len);
		ft_putstr(hexadecimal);
		space_printer(data_list);
		return (1);
	}
	return (x_simple_handler(hexadecimal, data_list, numb_len));
}

	// while (hexadecimal[i])
	// {
	// 	write(1, &hexadecimal[i], 1);
	// 	i++;
	// }
