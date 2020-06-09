# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 00:10:41 by deddara           #+#    #+#              #
#    Updated: 2020/06/10 00:17:51 by deddara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c


OBJ = $(SRC:.c=.o)
BONOBJ = $(BON:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):$(SRC)
	@clang -c -Wall -Wextra -Werror  $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(BONOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: all
