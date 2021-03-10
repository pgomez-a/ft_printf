#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		pf_man_fmt(va_list *ap, int ct, const char *format, char **width);

int		pf_man_pre(va_list *ap, int ct, const char *format, char **width);

void	pf_find_char(va_list *ap, char **width);

void	pf_find_pct(char **width);

void	pf_find_str(va_list *ap, char **width);

void	pf_find_int(va_list *ap, char **width);

int		int_man_pre(char **itoa, char **pre);

#endif
