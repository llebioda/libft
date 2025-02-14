/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:55:03 by llebioda          #+#    #+#             */
/*   Updated: 2025/02/14 15:59:30 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_atod_loop(const char *nptr)
{
	double	result;
	double	fraction;
	int		has_fraction;

	result = 0.0;
	fraction = 0.1;
	has_fraction = 0;
	while ((*nptr >= '0' && *nptr <= '9') || *nptr == '.')
	{
		if (*nptr == '.')
		{
			if (has_fraction)
				break ;
			has_fraction = 1;
		}
		else if (!has_fraction)
			result = result * 10.0 + (*nptr - '0');
		else
		{
			result += (*nptr - '0') * fraction;
			fraction *= 0.1;
		}
		nptr++;
	}
	return (result);
}

double	ft_atod(const char *nptr)
{
	double	result;
	int		is_negative;

	if (!nptr)
		return (0.0);
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	is_negative = 0;
	if (*nptr == '-')
		is_negative = 1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	result = ft_atod_loop(nptr);
	if (is_negative)
		return (-result);
	return (result);
}
