# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 15:51:04 by nsehnoun          #+#    #+#              #
#    Updated: 2017/12/07 08:28:40 by nsehnoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  miscellanious.c \
	  builtin.c \
	  builtin_2.c \
	  binaries.c \
	  env.c \
	  bt_cd.c \
	  bt_echo.c \
	  env_2.c \

NAME = minishell 

LIB = -Llibft -lft

HEADERS = minishell.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
