/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendwith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:11:54 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/25 11:23:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strendwith(const char *str, const char *end)
{
	int	i;
	int	j;

	if (!str || !end)
		return (0);
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (end[j])
		j++;
	if (j > i)
		return (0);
	while (j >= 0)
	{
		if (str[i] != end[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
