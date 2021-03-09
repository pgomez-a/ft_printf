/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:20:24 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/19 08:47:55 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			count;

	count = 0;
	temp = (unsigned char *)s;
	while (count < n)
	{
		if (temp[count] == (unsigned char)c)
			return (temp + count);
		count++;
	}
	return (0);
}
