/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:48:13 by luhego            #+#    #+#             */
/*   Updated: 2022/10/31 19:16:34 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*first_lst;

	if (!lst || !f || !del)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	first_lst = tmp;
	while (lst->next)
	{
		if (!tmp)
		{
			ft_lstclear(&first_lst, del);
			return (NULL);
		}
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		tmp = tmp->next;
	}
	return (first_lst);
}
