/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:56:13 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/04 11:35:47 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_str_num(char *str, int n, int len)
{
	int	mod;
	int	neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	str[len--] = '\0';
	while (len > 1)
	{
		mod = (n % 10) * neg;
		str[len--] = mod + '0';
		n /= 10;
	}
	if (neg == 1)
	{
		str[len] = (n % 10) + '0';
		str[0] = (n / 10) + '0';
	}
	else if (neg == -1)
	{
		str[len] = (n * -1) + '0';
		str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_num;

	len_num = ft_len_num(n);
	if (n <= 0)
		len_num++;
	result = (char *)malloc((len_num + 1) * sizeof(char));
	if (!result)
		return (0);
	if (n > 0 && n < 10)
	{
		result[0] = n + '0';
		result[1] = '\0';
	}
	else
		result = ft_str_num(result, n, len_num);
	return (result);
}
