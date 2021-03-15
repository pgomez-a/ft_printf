/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:44:23 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/12 12:44:38 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	man_zero(char **itoa, char **pre)
{
	if (**pre == '0' || **pre == '\0')
	{
		free(*itoa);
		(*itoa) = ft_strdup("");
	}
	else if (**pre != '-')
		(**itoa) = ' ';
}

static void	man_neg_pre(char **itoa, char **pre)
{
	char	*aux;
	char	*temp;
	int		num_p;
	int		len_i;

	aux = ft_strdup(*itoa + 1);
	num_p = ft_atoi(*pre);
	len_i = ft_strlen(aux);
	while (num_p > len_i)
	{
		temp = aux;
		aux = ft_strjoin("0", aux);
		free(temp);
		num_p--;
	}
	temp = *itoa;
	(*itoa) = ft_strjoin("-", aux);
	free(temp);
	free(aux);
}

static int	int_pre(char **itoa, char **pre)
{
	char	*temp;
	int		num_p;
	int		len_i;

	(**pre) = '\0';
	(*pre)++;
	if (ft_atoi(*itoa) == 0 && (**pre <= '0' || **pre > '9'))
		man_zero(itoa, pre);
	else if (**itoa == '-')
		man_neg_pre(itoa, pre);
	else
	{
		num_p = ft_atoi(*pre);
		len_i = ft_strlen(*itoa);
		while (num_p > len_i)
		{
			temp = *itoa;
			(*itoa) = ft_strjoin("0", *itoa);
			free(temp);
			num_p--;
		}
	}
	if (ft_strchr(*pre, '-'))
		return (0);
	return (1);
}

void	pf_find_int(va_list *ap, char **width, int **result)
{
	char	*itoa;
	char	*pre;
	int		num;
	int		verif;

	num = va_arg(*ap, int);
	itoa = ft_itoa(num);
	pre = ft_strchr(*width, '.');
	verif = 0;
	if (pre)
		verif = int_pre(&itoa, &pre);
	if (ft_strchr(*width, '-'))
		man_neg_width(&itoa, width, result);
	else
		man_pos_width(verif, &itoa, width, result);
	free(itoa);
}
