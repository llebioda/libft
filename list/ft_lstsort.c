/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:13:00 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/19 11:05:18 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)(void *v1, void *v2, void *params),
	void *params)
{
	t_list	*sorted;
	t_list	*curr;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || cmp == NULL)
		return ;
	sorted = NULL;
	while (*lst != NULL)
	{
		curr = *lst;
		*lst = (*lst)->next;
		if (sorted == NULL || cmp(curr->content, sorted->content, params) <= 0)
		{
			curr->next = sorted;
			sorted = curr;
			continue ;
		}
		tmp = sorted;
		while (tmp->next != NULL
			&& cmp(curr->content, tmp->next->content, params) > 0)
			tmp = tmp->next;
		curr->next = tmp->next;
		tmp->next = curr;
	}
	*lst = sorted;
}
