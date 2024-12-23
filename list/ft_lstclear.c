/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:41:51 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/17 10:16:35 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ls;
	t_list	*temp;

	if (del == NULL)
		return ;
	ls = *lst;
	while (ls != NULL)
	{
		(*del)(ls->content);
		temp = ls->next;
		free(ls);
		ls = temp;
	}
	*lst = NULL;
}
