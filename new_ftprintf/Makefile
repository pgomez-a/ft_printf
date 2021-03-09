SRCS		= ft_printf.c manage_format.c manage_precision.c char_type.c pct_type.c str_type.c


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
