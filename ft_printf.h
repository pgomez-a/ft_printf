/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:09 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/11 10:25:17 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
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
