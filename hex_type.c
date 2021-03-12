/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:17 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 10:01:48 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_find_hex(va_list *ap, char c, char **width, int **result)
{
	char			*hextoa;
	char			*pre;
	int				verif;
	int				len;
	unsigned long	num;

	num = va_arg(*ap, unsigned long);
	ft_hextoa(num, &hextoa);
	if (c == 'x')
	{
		len = 0;
		while (hextoa[len])
		{
			hextoa[len] = ft_tolower(hextoa[len]);
			len++;
		}
	}
	pre = ft_strchr(*width, '.');
	verif = 0;
	if (pre)
		verif = int_man_pre(&hextoa, &pre);
	if (ft_strchr(*width, '-'))
		man_neg_width(&hextoa, width, result);
	else
		man_pos_width(verif, &hextoa, width, result);
	free(hextoa);
}
