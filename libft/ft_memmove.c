/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:12:43 by luhego            #+#    #+#             */
/*   Updated: 2022/10/03 18:45:26 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcopy(void *dest, const void *src, size_t n)
{
	unsigned char			*ptrdest;
	const unsigned char		*ptrsrc;
	size_t					i;

	ptrdest = dest;
	ptrsrc = src;
	i = n;
	if (ptrdest == 0 && ptrsrc == 0)
		return (0);
	while (i > 0)
	{
		i--;
		ptrdest[i] = ptrsrc[i];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		ft_memrcopy(dest, src, n);
	}
	return (dest);
}
