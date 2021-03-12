/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:00:55 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/01 09:03:23 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (lst)
	{
		aux = *lst;
		if (aux == NULL)
			*lst = new;
		else
		{
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = new;
		}
	}
}
