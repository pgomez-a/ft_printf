#include "ft_printf.h"

void	pf_find_uns(va_list *ap, char **width)
{
	char			*utoa;
	char			*pre;
	int				verif;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	utoa = ft_utoa(num);
	pre = ft_strchr(*width, '.');
	verif = 0;
	if (pre)
		verif = int_man_pre(&utoa, &pre);
	if (ft_strchr(*width, '-'))
		man_neg_width(&utoa, width);
	else
		man_pos_width(verif, &utoa, width);
}
