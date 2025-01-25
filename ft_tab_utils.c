/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:07:16 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/25 13:36:26 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	char	**t;
	int		i;

	if (tab == NULL || *tab == NULL)
		return ;
	t = *tab;
	*tab = NULL;
	i = 0;
	while (t[i] != NULL)
		free(t[i++]);
	free(t);
}

char	**ft_dup_char_array(char **array)
{
	char	**dup;
	int		size;
	int		i;

	if (array == NULL)
		return (NULL);
	size = 0;
	while (array[size] != NULL)
		size++;
	dup = ft_calloc(size + 1, sizeof(char *));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = ft_strdup(array[i]);
		if (dup[i] == NULL)
		{
			while (--i >= 0)
				free(dup[i]);
			return (free(dup), NULL);
		}
		i++;
	}
	return (dup);
}

char	**ft_realloc_char_tab(char **tab, size_t new_size)
{
	char	**new_tab;
	size_t	i;

	if (new_size == 0)
	{
		ft_free_tab(&tab);
		return (NULL);
	}
	new_tab = ft_calloc(new_size + 1, sizeof(char *));
	if (new_tab == NULL)
	{
		ft_free_tab(&tab);
		return (NULL);
	}
	if (tab == NULL)
		return (new_tab);
	i = 0;
	while (tab[i] != NULL && i < new_size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	free(tab);
	return (new_tab);
}
