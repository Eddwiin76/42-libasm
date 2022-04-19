# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 11:22:30 by tpierre           #+#    #+#              #
#    Updated: 2020/10/23 13:52:11 by tpierre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libasm.a

SRCS			= srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s\
					srcs/ft_write.s srcs/ft_read.s srcs/ft_strdup.s

OBJS			= $(SRCS:.s=.o)

HEADER			= includes/libasm.h

NASM			= nasm

NFLAGS			= -felf64

AR				= ar rc

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.s
				$(NASM) $(NFLAGS) -s $< -o $(<:.s=.o)

main:			$(NAME)
				$(CC) $(CFLAGS) main.c -L. -lasm

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
