/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 02:44:36 by deddara           #+#    #+#             */
/*   Updated: 2020/06/19 22:22:42 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_FUNCS_H
# define ADDITIONAL_FUNCS_H
# include "ft_printf.h"

int				ft_isdigit(int c);
void			ft_lstclear(t_data *data_list);
t_data			*ft_lstnew();
int				num_len(int n);
int				l_num_len(long int n);
int				ll_num_len(long long int n);
int				hh_num_len(signed char n);
void			ft_putnbr(int n);
void			ft_l_putnbr(long int n);
void			ft_ll_putnbr(long long int n);
void			ft_hh_putnbr(signed char n);
void			ft_putstr(char *s);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *s);
void			ft_u_putnbr(unsigned int n);
void			ft_u_l_putnbr(unsigned long int n);
void			ft_u_ll_putnbr(size_t n);
void			ft_u_hh_putnbr(unsigned char n);
int				unum_len(unsigned int n);
int				unum_l_len(unsigned long int n);
int				unum_ll_len(size_t n);
int				unum_h_len(unsigned short int n);
int				unum_hh_len(unsigned char n);

#endif
