#include "ft_printf.h"

static void	ptr_pos_width(char **pointer, char **width)
{
	int	num;

	num = ft_atoi(*width) - ft_strlen(*pointer);
	while (num > 0)
	{
		if (**width == '0')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		num--;
	}
	ft_putstr_fd(*pointer, 1);
}

static void	ptr_neg_width(char **pointer, char **width)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - ft_strlen(*pointer);
	ft_putstr_fd(*pointer, 1);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		num--;
	}
}

void	find_ptr(va_list *ap, char **width)
{
	char			*pointer;
	char			*pre;
	int				len;
	unsigned long	num;

	pointer = NULL;
	num = va_arg(*ap, unsigned long);
	ft_hextoa(num, &pointer);
	len = 0;
	while (pointer[len])
	{
		pointer[len] = ft_tolower(pointer[len]);
		len++;
	}
	pre = pointer;
	pointer = ft_strjoin("0x", pointer);
	free(pre);
	pre = ft_strchr(*width, '.');
	if (pre)
		int_man_pre(&pointer, &pre);
	if (ft_strchr(*width, '-'))
		ptr_neg_width(&pointer, width);
	else
		ptr_pos_width(&pointer, width);
	free(pointer);
}
