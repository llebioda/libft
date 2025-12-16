/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:38:45 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/17 10:16:12 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			*wp;

	if (!s)
		return ;
	p = (unsigned char *)s;
	while (n && ((uintptr_t)p & (sizeof(size_t) - 1)))
	{
		*p++ = 0;
		n--;
	}
	wp = (size_t *)p;
	while (n >= sizeof(size_t))
	{
		*wp++ = 0;
		n -= sizeof(size_t);
	}
	p = (unsigned char *)wp;
	while (n--)
		*p++ = 0;
}
