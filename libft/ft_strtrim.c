/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:08:33 by luhego            #+#    #+#             */
/*   Updated: 2022/10/15 17:21:11 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimed_str;
	size_t			end;
	unsigned int	start;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end - 1]))
		end--;
	if (end < 1)
		return (ft_calloc(1, 1));
	trimed_str = ft_substr(s1, start, end - start);
	return (trimed_str);
}
