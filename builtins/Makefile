# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 13:12:34 by thbierne          #+#    #+#              #
#    Updated: 2022/06/19 09:54:43 by alewalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_LIB = ./includes/libft
LIB = $(DIR_LIB)/libft.a

SRCS = 	main.c						\
		srcs/alloc_cmd.c			\
		srcs/ft_echo.c 				\
		srcs/ft_env.c				\
		srcs/ft_pwd.c				\
		srcs/ft_cd.c				\
		srcs/ft_export.c 			\
		srcs/ft_signal.c			\
		srcs/ft_envp_to_envl.c		\
		srcs/ft_envl_utils.c		\
		srcs/ft_envl_to_envp.c		\
		srcs/ft_replace_dollar.c	\
		srcs/ft_path.c				\
		srcs/ft_test_cmd.c			\
		srcs/ft_unset.c				\

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