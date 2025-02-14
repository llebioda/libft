/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:55:18 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/14 16:04:36 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dtoa2(char *int_str, char *frac_str)
{
	char	*result;
	int		i;

	if (int_str == NULL || frac_str == NULL)
		return (NULL);
	result = ft_strjoin(int_str, frac_str);
	if (result == NULL)
		return (NULL);
	i = ft_strlen(result) - 1;
	while (i >= 0 && result[i] == '0')
		result[i--] = '\0';
	if (i > 0 && result[i] == '.')
		result[i] = '\0';
	return (result);
}

char	*ft_dtoa(double num, int precision)
{
	char	*result;
	double	fraction;
	char	*int_str;
	char	*frac_str;
	int		i;

	fraction = num - (int)num;
	if (fraction < 0)
		fraction = -fraction;
	int_str = ft_itoa((int)num);
	frac_str = ft_calloc(precision + 2, sizeof(char));
	if (int_str == NULL || frac_str == NULL)
		return (free(int_str), free(frac_str), NULL);
	frac_str[0] = '.';
	i = 1;
	while (i <= precision)
	{
		fraction *= 10;
		frac_str[i++] = ((int)fraction % 10) + '0';
	}
	result = ft_dtoa2(int_str, frac_str);
	free(int_str);
	free(frac_str);
	return (result);
}
