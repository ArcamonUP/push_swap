# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 10:58:52 by kbaridon          #+#    #+#              #
#    Updated: 2024/12/08 14:30:27 by kbaridon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(SRCDIR)
EXEC = push_swap
SRCDIR = src
SRCDIRB = srcbonus
LIBFT = libft
INCDIR = $(LIBFT)
HEADERS = $(SRCDIR)/push_swap.h $(LIBFT)/libft.h $(SRCDIRB)/checker.h

SRC =	init.c \
		possible_move_1.c \
		possible_move_2.c \
		possible_move_3.c \
		sort_dispatch.c \
		sort.c \
		push_to_a.c \
		sort_small.c \
		utils.c \
		free_stack.c
SRCMAIN = push_swap.c
SRCB = checker.c

OBJS = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))
OBJMAIN = $(addprefix $(SRCDIR)/, $(SRCMAIN:.c=.o))
OBJSB = $(addprefix $(SRCDIRB)/, $(SRCB:.c=.o))

all: $(EXEC)

push_swap: $(OBJS) $(OBJMAIN)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(OBJMAIN) $(LIBFT)/libft.a -o $(EXEC)

checker: $(OBJS) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSB) $(LIBFT)/libft.a -o checker

bonus: $(EXEC) checker

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJS): $(HEADERS)
$(OBJMAIN): $(HEADERS)
$(OBJSB): $(HEADERS)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(OBJMAIN)
	rm -rf $(OBJSB)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(EXEC)
	rm -rf $(EXEC) checker

re:	fclean all

.PHONY: all bonus clean fclean re
