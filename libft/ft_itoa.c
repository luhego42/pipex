/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:20:49 by luhego            #+#    #+#             */
/*   Updated: 2022/10/14 16:53:23 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(int n_len, int n, char *str)
{
	while (n_len >= 0)
	{
		str[n_len] = n % 10 + 48;
		n = n / 10;
		n_len--;
	}
}

static int	ft_n_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		negative;
	int		n_len;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative++;
		n = n * (-1);
	}
	n_len = ft_n_len(n) + negative;
	str = malloc(sizeof(char) * (n_len + 1));
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	n_len--;
	ft_convert(n_len, n, str);
	if (negative == 1)
		str[0] = '-';
	return (str);
}
