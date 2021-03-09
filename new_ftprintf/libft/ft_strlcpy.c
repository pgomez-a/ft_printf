/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:40:37 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/01/28 13:57:02 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count;
	unsigned int	output;

	if (!dst && !src)
		return (0);
	output = 0;
	while (src[output] != '\0')
		output++;
	if (dstsize == 0)
		return (output);
	count = 0;
	while (src[count] != '\0' && count < (dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count++] = '\0';
	return (output);
}
