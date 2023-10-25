/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:23:20 by luhego            #+#    #+#             */
/*   Updated: 2022/10/15 18:03:29 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2);
	str = ft_calloc(len_s1 + len_s2, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, len_s1);
	ft_strlcat(str, s2, len_s1 + len_s2);
	return (str);
}
