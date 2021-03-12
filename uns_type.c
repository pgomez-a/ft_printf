/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:45:46 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 08:56:38 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_find_uns(va_list *ap, char **width, int **result)
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
		man_neg_width(&utoa, width, result);
	else
		man_pos_width(verif, &utoa, width, result);
}
