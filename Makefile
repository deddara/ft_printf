# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 00:10:41 by deddara           #+#    #+#              #
#    Updated: 2020/06/21 14:58:29 by deddara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJDIR = obj/
SRC = d_h_handler d_handler d_hh_handler\
d_l_handler d_ll_handler data_processing\
double_rounder f_handler ft_form_parser\
ft_form_parser_add ft_isdigit ft_lstclear\
ft_lstclear_and_n ft_lstnew ft_num_len\
ft_printf ft_putnbr ft_putnbr_ll ft_putstr_fd\
ft_strdup ft_strlen ft_u_ll_putnbr ft_u_putnbr\
ft_unum_len inf_nan n_handler p_handler percent_handler\
s_handler u_h_handler u_handler u_hh_handler u_l_handler\
u_ll_handler x_grt_h_handler x_grt_handler x_grt_hh_handler\
x_grt_l_handler x_grt_ll_handler x_h_handler x_hh_handler\
x_handler x_l_handler x_ll_handler

OBJ = $(addprefix $(OBJDIR), $(SRC:=.o))

.PHONY: all clean fclean re bonus

all: $(OBJDIR) $(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

$(OBJ): $(OBJDIR)%.o: $(SRCDIR)%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all
