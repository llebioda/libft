/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:31:30 by llebioda          #+#    #+#             */
/*   Updated: 2025/07/08 11:45:27 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_char_number(long nb)
{
	int	a;

	a = 0;
	if (nb < 0)
	{
		a++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		a++;
	}
	return (a + 1);
}

char	*ft_ltoa(long nb)
{
	char	*dest;
	int		dest_len;
	int		i;
	int		is_neg;

	if (nb == INT64_MIN)
		return (ft_strdup("-9223372036854775808"));
	dest_len = get_char_number(nb);
	dest = ft_calloc(dest_len + 1, 1);
	if (dest == NULL)
		return (NULL);
	i = dest_len - 1;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		dest[0] = '-';
		nb = -nb;
	}
	while (i >= is_neg)
	{
		dest[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (dest);
}

static int	get_char_number_unsigned(unsigned long nb)
{
	int	a;

	a = 0;
	while (nb >= 10)
	{
		nb /= 10;
		a++;
	}
	return (a + 1);
}

char	*ft_ultoa(unsigned long nb)
{
	char	*dest;
	int		dest_len;
	int		i;

	dest_len = get_char_number_unsigned(nb);
	dest = ft_calloc(dest_len + 1, 1);
	if (dest == NULL)
		return (NULL);
	i = dest_len - 1;
	while (i >= 0)
	{
		dest[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (dest);
}
