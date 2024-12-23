/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:08:51 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/23 15:00:37 by llebioda         ###   ########.fr       */
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

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s3;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s3 = ft_strlen(s3);
	dst = malloc(len_s1 + len_s2 + len_s3 + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1 || i < len_s2 || i < len_s3)
	{
		if (i < len_s1)
			dst[i] = s1[i];
		if (i < len_s2)
			dst[i + len_s1] = s2[i];
		if (i < len_s3)
			dst[i + len_s1 + len_s2] = s3[i];
		i++;
	}
	dst[len_s1 + len_s2 + len_s3] = '\0';
	return (dst);
}
