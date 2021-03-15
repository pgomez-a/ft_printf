# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 08:43:38 by pgomez-a          #+#    #+#              #
#    Updated: 2021/03/11 10:25:20 by pgomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c manage_format.c manage_precision.c char_type.c pct_type.c str_type.c int_type.c uns_type.c hex_type.c ptr_type.c pointer_precision.c numbers_width.c


OBJS		= $(SRCS:.c=.o)

LIBFT_OBJS	= ./libft/*.o

NAME		= libftprintf.a

RM		= rm -f

CC		= gcc

CFLAGS		= -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./libft
	@ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJS)

fclean:		clean
	@make fclean -C ./libft
	@$(RM) $(NAME)

re:		fclean all

c:
	@$(CC) main.c -L. -lftprintf && ./a.out

cc:
	@$(CC) $(CFLAGS) main.c -L. -lftprintf && ./a.out
