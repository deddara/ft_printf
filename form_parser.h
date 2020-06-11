/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:27:29 by deddara           #+#    #+#             */
/*   Updated: 2020/06/11 07:20:56 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_PARSER_H
# define FORM_PARSER_H

# define NO_FLAG	0b00000000
# define NO_SPEC	0b00000000

# define NULL_FLAG	0b00000001
# define MINUS_FLAG	0b00000010
# define PLUS_FLAG	0b00000100
# define HASH_FLAG	0b00001000
# define SPACE_FLAG 0b00010000

# define L_SPEC		0b00000001
# define LL_SPEC	0b00000010
# define H_SPEC		0b00000100
# define HH_SPEC	0b00001000

typedef	struct		s_data
{
	unsigned char	flags;
	int	width;
	int	precision;
	unsigned char	l_specifier;
	char			type;
	unsigned int	len;
	char			*null_str;
	struct s_data	*next;
}					t_data;


#endif
