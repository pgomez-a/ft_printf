/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:50:21 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/01/28 14:15:58 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	count;
	size_t	limit;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len || dstsize == 0)
		return (dstsize + s_len);
	count = 0;
	limit = d_len;
	while (src[count] && count < (dstsize - d_len - 1))
	{
		dst[limit] = src[count];
		count++;
		limit++;
	}
	dst[limit] = '\0';
	return (d_len + s_len);
}
