/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstartwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:11:54 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/25 11:23:20 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstartwith(const char *str, const char *start)
{
	if (!str || !start)
		return (0);
	if (str == start || *start == '\0')
		return (1);
	while (*str && *str == *start)
	{
		str++;
		start++;
	}
	return (*start == '\0');
}
