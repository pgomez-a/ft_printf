/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:45:21 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 08:53:25 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pct_pos_width(char **width, int **result)
{
	int	num;

	num = ft_atoi(*width) - 1;
	while (num > 0)
	{
		if (**width == '0')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
	ft_putchar_fd('%', 1);
	(**result) += 1;
}

static void	pct_neg_width(char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - 1;
	ft_putchar_fd('%', 1);
	(**result) += 1;
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
}

void	pf_find_pct(char **width, int **result)
{
	char	*pre;

	pre = ft_strchr(*width, '.');
	if (pre)
		*pre = '\0';
	if (ft_strchr(*width, '-'))
		pct_neg_width(width, result);
	else
		pct_pos_width(width, result);
}
