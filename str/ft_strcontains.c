/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:43:09 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/23 13:45:31 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcontains(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	if (*str == c)
		return (1);
	return (0);
}
