#include "ft_printf.h"

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
