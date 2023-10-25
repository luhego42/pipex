/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:07:52 by luhego            #+#    #+#             */
/*   Updated: 2023/07/25 17:34:19 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long nbr, char *base, int *count)
{
	long long	base_len;

	base_len = ft_strlen(base);
	if (nbr >= 0 && nbr < base_len)
		ft_putchar_count(base[nbr], count);
	else if (nbr < 0)
	{
		ft_putchar_count('-', count);
		ft_putnbr_base(nbr * (-1), base, count);
	}
	else
	{
		ft_putnbr_base(nbr / base_len, base, count);
		ft_putnbr_base(nbr % base_len, base, count);
	}
}
