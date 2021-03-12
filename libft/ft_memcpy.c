/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:39:55 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/19 08:47:28 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_t;
	unsigned char	*src_t;
	size_t			count;

	if (dst == NULL && src == NULL)
		return (NULL);
	count = 0;
	dst_t = (unsigned char *)dst;
	src_t = (unsigned char *)src;
	while (count < n)
	{
		dst_t[count] = src_t[count];
		count++;
	}
	return (dst);
}
