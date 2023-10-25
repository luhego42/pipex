/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:22:47 by luhego            #+#    #+#             */
/*   Updated: 2022/10/26 18:35:45 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		list_len;
	t_list	*tmp;

	tmp = lst;
	list_len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		list_len++;
	}
	return (list_len);
}
