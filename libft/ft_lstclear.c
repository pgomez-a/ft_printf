/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:00:18 by pgomez-a          #+#    #+#             */
/*   Updated: 2021/02/01 09:00:21 by pgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*current;

	current = *lst;
	while (current)
	{
		aux = current->next;
		(*del)(current->content);
		free(current);
		current = aux;
	}
	(*lst) = NULL;
}
