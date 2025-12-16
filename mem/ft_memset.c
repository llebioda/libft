/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:31:34 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/25 12:16:35 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			cword;
	size_t			i;

	if (!s)
		return (s);
	p = (unsigned char *)s;
	while (n && ((uintptr_t)p & (sizeof(size_t) - 1)))
	{
		*p++ = (unsigned char)c;
		n--;
	}
	cword = 0;
	i = 0;
	while (i++ < sizeof(size_t))
		cword = (cword << 8) | (unsigned char)c;
	while (n >= sizeof(size_t))
	{
		*((size_t *)p) = cword;
		p += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
