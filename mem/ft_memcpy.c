/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:31:34 by llebioda          #+#    #+#             */
/*   Updated: 2024/12/17 10:16:51 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memmove(void *dst, const void *src, size_t n);

static void	ft_memcpy_copy(unsigned char *dst, const unsigned char *src, size_t n)
{
	size_t			*dw;
	const size_t	*sw;

	while (n && ((uintptr_t)dst & (sizeof(size_t) - 1)))
	{
		*dst++ = *src++;
		n--;
	}
	dw = (size_t *)dst;
	sw = (const size_t *)src;
	while (n >= sizeof(size_t))
	{
		*dw++ = *sw++;
		n -= sizeof(size_t);
	}
	dst = (unsigned char *)dw;
	src = (const unsigned char *)sw;
	while (n--)
		*dst++ = *src++;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uintptr_t	d;
	uintptr_t	s;

	if (!dst || !src)
		return (dst);
	d = (uintptr_t)dst;
	s = (uintptr_t)src;
	if ((d < s && d + n > s) || (s < d && s + n > d))
		return (ft_memmove(dst, src, n));
	ft_memcpy_copy(dst, src, n);
	return (dst);
}
