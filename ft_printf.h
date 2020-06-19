/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:23:28 by deddara           #+#    #+#             */
/*   Updated: 2020/06/19 21:15:12 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "form_parser.h"
# include "additional_funcs.h"

# define DBL_INF	0x7FF0000000000000
# define DBL_NINF	0xFFF0000000000000
# define DBL_NAN	0x7FF0000000100000

int		ft_printf(const char *str, ...);
char	*form_parser(const char *str, va_list *args, int *count);
int		data_processing(t_data *data_list, va_list **args);
int		l_num_len(long int n);
int		ll_num_len(long long int n);
void	space_printer(t_data *data_list);
int		d_handler(t_data *data_list, va_list ***args);
int		string_handler(t_data *data_list, va_list ***args);
int		u_handler(t_data *data_list, va_list ***args);
void	u_precision_print_handler(t_data *data_list, int numb_len);
int		u_l_handler(t_data *data_list, va_list ***args);
int		u_ll_handler(t_data *data_list, va_list ***args);
int		u_h_handler(t_data *data_list, va_list ***args);
int		u_hh_handler(t_data *data_list, va_list ***args);
int		x_handler(t_data *data_list, va_list ***args);
int		x_l_handler(t_data *data_list, va_list ***args);
int		x_ll_handler(t_data *data_list, va_list ***args);
int		x_h_handler(t_data *data_list, va_list ***args);
int		x_hh_handler(t_data *data_list, va_list ***args);
int		x_grt_l_handler(t_data *data_list, va_list ***args);
int		x_grt_ll_handler(t_data *data_list, va_list ***args);
int		x_grt_h_handler(t_data *data_list, va_list ***args);
int		x_grt_hh_handler(t_data *data_list, va_list ***args);
int		x_precision_handler(char *hex, t_data *data_list, int numb_len);
int		x_simple_handler(char *hex, t_data *data_list, int numb_len);
void	hash_check(t_data *data_list, char *hex);
void	x_precision_print_handler(t_data *data_list, int n_len, char *hex);
int		greater_x_handler(t_data *data_list, va_list ***args);
int		p_handler(t_data *data_list, va_list ***args);
int		percent_handler(t_data *data_list);
int		l_d_handler(t_data *data_list, va_list ***args);
int		ll_d_handler(t_data *data_list, va_list ***args);
int		h_d_handler(t_data *data_list, va_list ***args);
int		hh_d_handler(t_data *data_list, va_list ***args);
void	ft_ll_putnbr(long long int n);
char	*get_l_specifier(const char *str, t_data *data_list);
void	n_handler(t_data *data_list, va_list ***args, int len);
int		f_handler(t_data *data_list, va_list ***args);
void	ft_lstclear_and_n(t_data *data_list, va_list **args, int len);

#endif
