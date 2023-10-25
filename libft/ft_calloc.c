/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:57:48 by luhego            #+#    #+#             */
/*   Updated: 2022/10/05 16:35:16 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb * size > INT_MAX || size > INT_MAX || nmemb > INT_MAX)
		return (0);
	str = malloc(size * nmemb);
	if (str == 0)
		return (0);
	ft_bzero(str, size * nmemb);
	return (str);
}
