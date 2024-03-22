/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:48:21 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/21 17:28:43 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_list;
	int		temp;
	t_list	*to_add;

	new_list = NULL;
	while (lst != NULL)
	{
		temp = (f)(lst->content);
		to_add = ft_lstnew(temp);
		if (to_add == NULL)
		{
			(del)(temp);
			return (ft_lstclear(&new_list, del), NULL);
		}
		ft_lstadd_back(&new_list, to_add);
		lst = lst->next;
	}
	return (new_list);
}
