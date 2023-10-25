/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:16:59 by luhego            #+#    #+#             */
/*   Updated: 2023/07/25 17:46:58 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_count(const char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_count("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar_count(str[i], count);
		i++;
	}
}
