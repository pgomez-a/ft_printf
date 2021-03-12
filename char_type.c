/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:43:48 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 08:52:03 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	char_pos_width(char c, char **width, int **result)
{
	int	num;

	num = ft_atoi(*width) - 1;
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
	ft_putchar_fd(c, 1);
	(**result) += 1;
}

static void	char_neg_width(char c, char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - 1;
	ft_putchar_fd(c, 1);
	(**result) += 1;
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
}

void	pf_find_char(va_list *ap, char **width, int **result)
{
	char	*pre;
	char	c;

	c = va_arg(*ap, int);
	pre = ft_strchr(*width, '.');
	if (pre)
		*pre = '\0';
	if (**width == '-')
		char_neg_width(c, width, result);
	else
		char_pos_width(c, width, result);
}
