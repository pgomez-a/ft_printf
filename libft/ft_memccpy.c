/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:11:14 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/19 08:47:42 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_1;
	unsigned char	*src_1;
	size_t			count;

	count = 0;
	dst_1 = (unsigned char *)dst;
	src_1 = (unsigned char *)src;
	while (count < n)
	{
		dst_1[count] = src_1[count];
		if (src_1[count] == (unsigned char)c)
			return (dst + count + 1);
		count++;
	}
	return (NULL);
}
