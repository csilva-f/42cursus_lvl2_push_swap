# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/01/26 23:19:31 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = clang
CFLAGS = -g -Wall -Werror -Wextra

SRCS = index_position.c push_swap.c operations.c operations_2.c operations_3.c sort_stack.c \
	   sort_stack_2.c sort_stack_3.c stack.c stack_2.c

SRCS_BONUS = checker.c operations_bonus.c operations_bonus_2.c operations_bonus_3.c stack_bonus.c \
			 stack_bonus_2.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}

bonus: $(BONUS) 

$(BONUS): $(OBJS_BONUS) $(LIBFT)
		${CC} ${FLAGS} ${OBJS_BONUS} ${LIBFT} -o ${BONUS}

$(LIBFT):
		${MAKE} -C ./libft

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS}
		rm -rf ${OBJS_BONUS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)
		rm -rf $(BONUS)

re:	fclean all bonus

.SILENT:
