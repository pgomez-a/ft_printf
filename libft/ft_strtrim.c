/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 08:26:38 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/03/04 11:25:23 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_begin(char const *s1, char const *s2)
{
	int	count;
	int	count_2;

	count = 0;
	count_2 = 0;
	while (s2[count_2])
	{
		if (s2[count_2] != s1[count])
			count_2++;
		else if (s1[count + 1])
		{
			count++;
			count_2 = 0;
		}
		else
			return (-1);
	}
	return (count);
}

static int	ft_num_end(char const *s1, char const *s2)
{
	int	count;
	int	count_2;

	count = 0;
	count_2 = 0;
	while (s1[count])
		count++;
	count--;
	while (s2[count_2])
	{
		if (s2[count_2] != s1[count])
			count_2++;
		else if (count > 0)
		{
			count--;
			count_2 = 0;
		}
		else
			return (-1);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*result;
	int		begin;
	int		end;
	int		count;

	if (!s1 || !s2)
		return (NULL);
	begin = ft_num_begin(s1, s2);
	end = ft_num_end(s1, s2);
	count = end - begin;
	result = (char *)malloc((count + 2) * sizeof(char));
	if (!result)
		return (0);
	count = 0;
	if (begin + end >= 0)
	{
		while (begin <= end)
		{
			result[count] = s1[begin];
			begin++;
			count++;
		}
	}
	result[count] = '\0';
	return (result);
}
