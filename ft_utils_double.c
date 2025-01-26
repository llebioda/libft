/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:19:57 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/26 13:51:34 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_db(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

double	ft_abs_db(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

double	ft_min_db(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	ft_max_db(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

double	ft_clamp_db(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
