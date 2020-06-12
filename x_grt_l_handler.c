/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_grt_l_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 09:44:07 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 09:44:50 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	converter(char *hexadecimal, unsigned long int res)
{
	int j;
	int i;
	long int backup;
	char		*reverse;

	if (!(reverse = (char *)malloc(sizeof(char) * 100)))
		return ;
	j = 0;
	i = 0;
	while (res != 0)
	{
		backup = res % 16;
		if (backup < 10)
			reverse[j++] = 48 + backup;
		else
			reverse[j++] = 55 + backup;
		res /= 16;
	}
	hexadecimal[j] = 0;
	j--;
	while (j >= 0)
		hexadecimal[i++] = reverse[j--];
	free (reverse);
}

int	x_grt_l_handler(t_data *data_list, va_list ***args)
{
	unsigned long int				res;
	char			hexadecimal[100];
	int				numb_len;

	res = va_arg(***args, unsigned long int);
	if (data_list->precision == 0 && !res)
	{
		data_list->len = 0;
		space_printer(data_list);
		return (1);
	}
	converter(hexadecimal, res);
	if(!(numb_len = ft_strlen(hexadecimal)))
		numb_len = 1;
	data_list->len = numb_len;
	if ((data_list->precision != -1) && data_list->precision > numb_len)
		return (x_precision_handler(hexadecimal, data_list, numb_len));
	hash_check(data_list, hexadecimal);
	if ((data_list->flags & MINUS_FLAG))
	{
		x_precision_print_handler(data_list, numb_len, hexadecimal);
		ft_putstr(hexadecimal);
		space_printer(data_list);
		return (1);
	}
	return (x_simple_handler(hexadecimal, data_list, numb_len));
}
