/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:23:15 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/19 08:48:12 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_t;
	unsigned char	*s2_t;
	size_t			count;

	count = 0;
	s1_t = (unsigned char *)s1;
	s2_t = (unsigned char *)s2;
	while (count < n)
	{
		if (s1_t[count] != s2_t[count])
			return (s1_t[count] - s2_t[count]);
		count++;
	}
	return (0);
}
