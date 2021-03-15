/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:45:11 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 12:48:11 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	posw_neg_int(int verif, char **number, char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strdup(*number + 1);
	num = ft_atoi(*width) - ft_strlen(*number);
	if (verif != 1)
		ft_putchar_fd('-', 1);
	while (num > 0)
	{
		if (*(*number + 1) != '0' && verif != 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
	if (verif == 1)
		ft_putchar_fd('-', 1);
	(**result) += 1;
	ft_putstr_fd(aux, 1);
	(**result) += ft_strlen(aux);
	free(aux);
}

void	man_pos_width(int verif, char **number, char **width, int **result)
{
	int	num;

	if (**number == '-' && (**width) == '0')
		posw_neg_int(verif, number, width, result);
	else
	{
		num = ft_atoi((*width)) - (int)ft_strlen(*number);
		while (num > 0)
		{
			if (**width == '0' && **number != '0' && verif != 1)
				ft_putchar_fd('0', 1);
			else if (**width == '0' && ft_atoi(*number) == 0
				&& ft_strlen(*number) == 1 && verif != 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			(**result) += 1;
			num--;
		}
		ft_putstr_fd(*number, 1);
		(**result) += ft_strlen(*number);
	}
}

void	man_neg_width(char **number, char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - ft_strlen(*number);
	ft_putstr_fd(*number, 1);
	(**result) += ft_strlen(*number);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
}
