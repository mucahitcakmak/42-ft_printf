# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 11:42:14 by mucakmak          #+#    #+#              #
#    Updated: 2023/07/19 11:43:10 by mucakmak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c ft_puts.c
OBJS 	= 	$(SRC:.c=.o)

NAME	=	libftprintf.a

CC 		= 	gcc
CFLAGS 	= 	-Wall -Werror -Wextra
RM	 	= 	rm -rf
AR 		= 	ar rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re


