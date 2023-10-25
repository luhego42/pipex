/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:10:42 by luhego            #+#    #+#             */
/*   Updated: 2022/10/14 17:17:29 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptrsrc;
	unsigned char	chr;
	size_t			i;

	ptrsrc = (unsigned char *)s;
	chr = c;
	i = 0;
	while (i < n)
	{
		if (ptrsrc[i] == chr)
			return (&ptrsrc[i]);
		i++;
	}
	if (chr == '\0')
		return (0);
	return (0);
}
