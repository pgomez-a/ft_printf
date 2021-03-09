/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:27:27 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/04 11:22:14 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = ft_strlen(s1);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
