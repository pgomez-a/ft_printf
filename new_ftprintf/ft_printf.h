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

void	pf_find_uns(va_list *ap, char **width);

void	pf_find_hex(va_list *ap, char c, char **width);

void	find_ptr(va_list *ap, char **width);

int		int_man_pre(char **number, char **pre);

void	man_pos_width(int verif, char **number, char **width);

void	man_neg_width(char **number, char **width);

#endif
