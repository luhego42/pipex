/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:26:59 by luhego            #+#    #+#             */
/*   Updated: 2022/10/05 14:33:31 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;
	int					result;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && ptr1[i] == ptr2[i])
		i++;
	result = ptr1[i] - ptr2[i];
	return (result);
}
