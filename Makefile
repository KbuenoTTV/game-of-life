#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/01 02:49:46 by jchichep          #+#    #+#              #
#    Updated: 2014/10/01 04:10:03 by jchichep         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= GoL

SRC			= main.c \
			  algo.c \
			  ft_functions.c

OBJ			= $(SRC:.c=.o)

CC			= /usr/bin/gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

ECHO		= echo

$(NAME)		: $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@$(ECHO) "\033[0;32m> Compiled\033[0m"

clean		:
	@$(RM) $(OBJ)
	@$(RM) *~
	@$(RM) #*#
	@$(ECHO) "\033[0;35m> Directory cleaned\033[0m"

all		: $(NAME)

fclean		: clean
	-@$(RM) $(NAME)
	@$(ECHO) "\033[0;35m> Remove executable\033[0m"

re		: fclean all

.PHONY : all clean fclean re

