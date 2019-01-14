# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 14:09:11 by pavaucha          #+#    #+#              #
#    Updated: 2018/10/02 10:48:25 by pavaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pavaucha.filler 

CC = gcc

CFLAGS = -Werror -Wextra -Wall

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft

LDLIBS = -lftprintf

SRC_NAME = get_next_line.c \
		   main.c \
		   ft_parse.c \
		   ft_put_piece.c \
		   ft_int_map.c \
		   ft_free_coord.c \
		  ft_strjoin_free.c 

SRC_PATH = ./sources
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./sources
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)
	@rm -rf ./objs
fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
