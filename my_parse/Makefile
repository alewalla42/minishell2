# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 13:12:34 by thbierne          #+#    #+#              #
#    Updated: 2022/08/30 22:57:10 by alewalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_LIB = ./includes/libft
LIB = $(DIR_LIB)/libft.a

SRCS = 	main.c						\
		ft_block_maker.c			\
		ft_parsing.c				\
		ft_putstruct.c				\
		ft_set_first_block.c		\
		ft_tokenl_utils.c			\
		

OBJS = $(SRCS:.c=.o)

CC = clang

INCLUDES = -I./includes -I./includes/libft
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -g -lreadline -o $(NAME) $(OBJS) $(LIB) 
	
$(LIB): $(DIR_LIB)
	@make -C $(DIR_LIB)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(DIR_LIB) clean

fclean: clean
	$(RM) $(NAME) pwd echo env export
	$(MAKE) -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re