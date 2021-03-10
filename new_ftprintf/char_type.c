#include "ft_printf.h"

static void	char_pos_width(char c, char **width)
{
	int	num;

	num = ft_atoi(*width) - 1;
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		num--;
	}
	ft_putchar_fd(c, 1);
}

static void	char_neg_width(char c, char **width)
{
	char	*aux;
	int		num;

	aux = *width;
	aux++;
	num = ft_atoi(aux) - 1;
	ft_putchar_fd(c, 1);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		num--;
	}
}

void	pf_find_char(va_list *ap, char **width)
{
	char	*pre;
	char	c;

	c = va_arg(*ap, int);
	pre = ft_strchr(*width, '.');
	if (pre)
		*pre = '\0';
	if (**width == '-')
		char_neg_width(c, width);
	else
		char_pos_width(c, width);
}
