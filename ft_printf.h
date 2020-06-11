/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:23:28 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 02:04:50 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "form_parser.h"

int	ft_isdigit(int c); //libft
t_data	*ft_lstnew(); //libft
int	ft_printf(const char *str, ...);
char	*form_parser(const char *str, va_list *args, int *count);
int data_processing(t_data *data_list, va_list **args);
int	num_len(int n);
int	l_num_len(long int n);
int	ll_num_len(long long int n);
void	ft_putnbr(int n);
void	ft_l_putnbr(long int n);
void space_printer(t_data *data_list);
int	d_handler(t_data *data_list, va_list ***args);
int char_handler(t_data *data_list, va_list ***args);
int	string_handler(t_data *data_list, va_list ***args);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int	u_handler(t_data *data_list, va_list ***args);
void			ft_u_putnbr(unsigned int n);
int	unum_len(unsigned int n);
int	x_handler(t_data *data_list, va_list ***args);
void	ft_putstr(char *s);
int x_precision_handler(char *hex,t_data *data_list, int numb_len);
int	x_simple_handler(char *hex, t_data *data_list, int numb_len);
void	hash_check(t_data *data_list, char *hex);
void	x_precision_print_handler(t_data *data_list, int numb_len, char *hex);
int	greater_x_handler(t_data *data_list, va_list ***args);
int	p_handler(t_data *data_list, va_list ***args);
void	ft_p_putstr(char *s);
int	percent_handler(t_data *data_list);
void	ft_lstclear(t_data *data_list);
int	l_d_handler(t_data *data_list, va_list ***args);

#endif
