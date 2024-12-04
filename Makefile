# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 10:58:52 by kbaridon          #+#    #+#              #
#    Updated: 2024/12/04 16:23:11 by kbaridon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
EXEC = push_swap
SRCDIR = src
LIBFT = libft
INCDIR = $(LIBFT)

SRC =	push_swap.c \
		init.c \
		possible_move_1.c \
		possible_move_2.c \
		possible_move_3.c \
		sort_dispatch.c \
		sort.c \
		push_to_a.c \
		sort_small.c \
		utils.c \
		free_stack.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(EXEC)

$(EXEC): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(EXEC)

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(EXEC)

re:	fclean all

.PHONY: all clean fclean re
