/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:20 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/11 13:03:20 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(char const *str, char const *set);
static int	contains(char const *str, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len;
	int		i;

	while (contains(set, *s1) == 1)
		s1++;
	len = count(s1, set);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	count(char const *str, char const *set)
{
	int	i;
	int	last_i;

	i = 0;
	last_i = 0;
	while (str[i])
	{
		if (contains(set, str[i]) == 0)
			last_i = i;
		i++;
	}
	return (last_i + 1);
}

static int	contains(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
