# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/01/14 23:31:59 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -g -Wall -Werror -Wextra

SRCS = index_position.c main.c operations.c operations_2.c operations_3.c sort_stack.c \
	   sort_stack_2.c sort_stack_3.c stack.c stack_2.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
		${MAKE} -C ./libft

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all
