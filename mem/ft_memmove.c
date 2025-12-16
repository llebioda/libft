/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:21:19 by llebioda          #+#    #+#             */
/*   Updated: 2024/11/25 11:50:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

static void	ft_memmove_forward(
	unsigned char *dst, const unsigned char *src, size_t n)
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

static void	ft_memmove_backward(
	unsigned char *dst, const unsigned char *src, size_t n)
{
	size_t			*dw;
	const size_t	*sw;

	dst += n;
	src += n;
	while (n && ((uintptr_t)dst & (sizeof(size_t) - 1)))
	{
		*(--dst) = *(--src);
		n--;
	}
	dw = (size_t *)dst;
	sw = (const size_t *)src;
	while (n >= sizeof(size_t))
	{
		dw--;
		sw--;
		*dw = *sw;
		n -= sizeof(size_t);
	}
	dst = (unsigned char *)dw;
	src = (const unsigned char *)sw;
	while (n--)
		*(--dst) = *(--src);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src || n == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
		ft_memmove_forward(d, s, n);
	else
		ft_memmove_backward(d, s, n);
	return (dst);
}
