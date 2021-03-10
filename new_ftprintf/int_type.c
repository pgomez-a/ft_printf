#include "ft_printf.h"

static void	man_posw_neg_int(int verif, char **itoa, char **width)
{
	char	*aux;
	int		num;

	aux = ft_strdup(*itoa + 1);
	num = ft_atoi(*width) - ft_strlen(*itoa);
	if (**width == '0' && *(*itoa + 1) != '0' && verif != 1)
		ft_putchar_fd('-', 1);
	while (num > 0)
	{
		if (**width == '0' && *(*itoa + 1) != '0' && verif != 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		num--;
	}
	if (verif == 1)
		ft_putchar_fd('-', 1);
	ft_putstr_fd(aux, 1);
	free(aux);
}

static void	man_pos_width(int verif, char **itoa, char **width)
{
	int		num;

	if (**itoa == '-' && (**width) == '0')
		man_posw_neg_int(verif, itoa, width);
	else
	{
		num = ft_atoi(*width) - ft_strlen(*itoa);
		while (num > 0)
		{
			if (**width == '0' && **itoa != '0' && verif != 1)
				ft_putchar_fd('0', 1);
			else if (**width == '0' && ft_atoi(*itoa) == 0
					&& ft_strlen(*itoa) == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			num--;
		}
		ft_putstr_fd(*itoa, 1);
	}
}

static void	man_neg_width(char **itoa, char **width)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - ft_strlen(*itoa);
	ft_putstr_fd(*itoa, 1);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		num--;
	}
}

void	pf_find_int(va_list *ap, char **width)
{
	char	*itoa;
	char	*pre;
	int		num;
	int		verif;

	num = va_arg(*ap, int);
	itoa = ft_itoa(num);
	pre = ft_strchr(*width, '.');
	verif = 0;
	if (pre)
		verif = int_man_pre(&itoa, &pre);
	if (ft_strchr(*width, '-'))
		man_neg_width(&itoa, width);
	else
		man_pos_width(verif, &itoa, width);
	free(itoa);
}
