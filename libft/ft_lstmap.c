/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:22:52 by jronald           #+#    #+#             */
/*   Updated: 2018/06/04 13:56:59 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *tail;

	if (!lst)
		return (NULL);
	tail = f(lst);
	head = tail;
	if (!(tail))
		return (NULL);
	while (lst->next && f(lst))
	{
		lst = lst->next;
		head->next = f(lst);
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (tail);
}
