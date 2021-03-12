/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:09:03 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/04 11:29:59 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	result = (char *)malloc((count + 1) * sizeof(char));
	if (!result)
		return (0);
	result[count] = '\0';
	while (count > 0)
	{
		count--;
		result[count] = (*f)(count, s[count]);
	}
	return (result);
}
