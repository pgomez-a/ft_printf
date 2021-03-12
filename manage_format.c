/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:34 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/11 10:25:12 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verif_errors(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'u'
		|| c == 'd' || c == 'i' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

static void	char_to_str(char c, char **width)
{
	char	cpy[2];
	char	*temp;

	cpy[0] = c;
	cpy[1] = '\0';
	temp = *width;
	(*width) = ft_strjoin(*width, cpy);
	free(temp);
}

static int	manage_num(int ct, const char *format, char **width)
{
	while (!verif_errors(format[ct]) && format[ct] != '.')
	{
		if (format[ct] < '0' || format[ct] > '9')
			break ;
		char_to_str(format[ct++], width);
	}
	return (ct);
}

static int	manage_ast(va_list *ap, int ct, const char *format, char **width)
{
	char	*itoa;
	char	*temp;
	int		num;

	if (format[ct] == '*')
	{
		num = va_arg(*ap, int);
		if (ft_strchr(*width, '-') && num < 0)
			num *= -1;
		itoa = ft_itoa(num);
		temp = *width;
		(*width) = ft_strjoin(*width, itoa);
		free(temp);
		free(itoa);
		return (ct + 1);
	}
	return (ct);
}

int	pf_man_fmt(va_list *ap, int ct, const char *format, char **width)
{
	if (format[ct] == '-')
	{
		(*width) = ft_strdup("-");
		ct++;
		while (format[ct] == '-')
			ct++;
	}
	else
		(*width) = ft_strdup("");
	while (format[ct] == '0')
		char_to_str(format[ct++], width);
	while (format[ct] == '-')
		char_to_str(format[ct++], width);
	ct = manage_ast(ap, ct, format, width);
	ct = manage_num(ct, format, width);
	ct = pf_man_pre(ap, ct, format, width);
	return (ct);
}
