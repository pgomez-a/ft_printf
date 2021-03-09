/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:20:30 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/19 08:47:10 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			count;

	count = 0;
	temp = (unsigned char *)b;
	while (count < len)
	{
		temp[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
