/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:20 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/23 18:32:10 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *str, char const *set)
{
	int	i;
	int	last_i;

	i = 0;
	last_i = 0;
	while (str[i])
	{
		if (ft_strcontains(set, str[i]) == 0)
			last_i = i;
		i++;
	}
	return (last_i + 1);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*dst;
	int		len;
	int		i;

	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(str));
	while (ft_strcontains(set, *str) == 1)
		str++;
	len = count(str, set);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
