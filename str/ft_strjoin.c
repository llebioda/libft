/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:08:51 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/17 10:17:03 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(len_s1 + len_s2 + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			dst[i] = s1[i];
		if (i < len_s2)
			dst[i + len_s1] = s2[i];
		i++;
	}
	dst[len_s1 + len_s2] = '\0';
	return (dst);
}
