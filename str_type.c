/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:45:36 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 08:55:06 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	man_pre(char **output, char **pre)
{
	char	*aux;
	int		num;

	(**pre) = '\0';
	(*pre)++;
	aux = *output;
	num = ft_atoi(*pre);
	if (num < (int)ft_strlen(*output) && num >= 0)
	{
		while (num > 0)
		{
			aux++;
			num--;
		}
		*aux = '\0';
	}
}

static void	str_pos_width(char **output, char **width, int **result)
{
	int	num;

	num = ft_atoi(*width) - ft_strlen(*output);
	while (num > 0)
	{
		if (**width == '0')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
	ft_putstr_fd(*output, 1);
	(**result) += ft_strlen(*output);
}

static void	str_neg_width(char **output, char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - ft_strlen(*output);
	ft_putstr_fd(*output, 1);
	(**result) += ft_strlen(*output);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
}

void	pf_find_str(va_list *ap, char **width, int **result)
{
	char	*str;
	char	*output;
	char	*pre;

	str = va_arg(*ap, char *);
	if (str)
		output = ft_strdup(str);
	else
		output = ft_strdup("(null)");
	pre = ft_strchr(*width, '.');
	if (pre)
		man_pre(&output, &pre);
	if (ft_strchr(*width, '-'))
		str_neg_width(&output, width, result);
	else
		str_pos_width(&output, width, result);
	free(output);
}
