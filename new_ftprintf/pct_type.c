#include "ft_printf.h"

static void	pct_pos_width(char **width)
{
	int	num;

	num = ft_atoi(*width) -1;
	while (num > 0)
	{
		if (**width == '0')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		num--;
	}
	ft_putchar_fd('%', 1);
}

static void	pct_neg_width(char **width)
{
	char	*aux;
	int	num;

	aux = *width;
	aux++;
	num = ft_atoi(aux) - 1;
	ft_putchar_fd('%', 1);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		num--;
	}
}

void	pf_find_pct(char **width)
{
	char	*pre;

	pre = ft_strchr(*width, '.');
	if (pre)
		*pre = '\0';
	if (**width == '-')
		pct_neg_width(width);
	else
		pct_pos_width(width);
}
