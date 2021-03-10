#include "ft_printf.h"

void	find_ptr(va_list *ap, char **width)
{
	ft_putstr_fd("0x", 1);
	pf_find_hex(ap, 'x', width);
}
