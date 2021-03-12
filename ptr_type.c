/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:45:29 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 09:34:18 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptr_pos_width(char **pointer, char **width, int **result)
{
	int	num;

	num = ft_atoi(*width) - ft_strlen(*pointer);
	while (num > 0)
	{
		if (**width == '0')
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
	ft_putstr_fd(*pointer, 1);
	(**result) += ft_strlen(*pointer);
}

static void	ptr_neg_width(char **pointer, char **width, int **result)
{
	char	*aux;
	int		num;

	aux = ft_strchr(*width, '-');
	aux++;
	num = ft_atoi(aux) - ft_strlen(*pointer);
	ft_putstr_fd(*pointer, 1);
	(**result) += ft_strlen(*pointer);
	while (num > 0)
	{
		ft_putchar_fd(' ', 1);
		(**result) += 1;
		num--;
	}
}

void	find_ptr(va_list *ap, char **width, int **result)
{
	char			*pointer;
	char			*pre;
	int				len;
	unsigned long	num;

	pointer = NULL;
	num = va_arg(*ap, unsigned long);
	ft_hextoa(num, &pointer);
	len = 0;
	while (pointer[len])
	{
		pointer[len] = ft_tolower(pointer[len]);
		len++;
	}
	if (!ft_strchr(*width, '.'))
	{
		len = -1;
		pre = pointer;
		pointer = ft_strjoin("0x", pointer);
		free(pre);
	}
	pre = ft_strchr(*width, '.');
	if (pre)
		int_man_pre(&pointer, &pre);
	if (len != -1)
	{
		pre = pointer;
		pointer = ft_strjoin("0x", pointer);
		free(pre);
	}
	if (ft_strchr(*width, '-'))
		ptr_neg_width(&pointer, width, result);
	else
		ptr_pos_width(&pointer, width, result);
	free(pointer);
}
