# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 16:11:32 by sancuta           #+#    #+#              #
#    Updated: 2026/03/30 01:40:58 by sancuta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRCS =	main.c \
		stack_utils.c \
		op_swap.c \
		op_push.c \
		op_rotate.c \
		op_revrotate.c \
		mini_sort.c \
		radix.c \
		cleanup.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: .release $(NAME)

.release:
	if [ -f .debug ]; then $(MAKE) fclean; fi
	touch .release

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): FORCE
	if [ -f .debug ]; then $(MAKE) -C libft debug; \
	else $(MAKE) -C libft; fi

FORCE:

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) .debug .release

re: fclean all

debug: CFLAGS += -g #-fsanitize=address,leak,undefined
debug: .debug $(NAME)

.debug:
	if [ -f .release ]; then $(MAKE) fclean; fi
	touch .debug

.PHONY: all clean fclean re debug FORCE

-include $(DEPS)
