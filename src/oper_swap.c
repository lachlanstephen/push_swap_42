/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:35:54 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/25 02:36:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_elem(t_list **stk, int count)
{
	t_list	*temp;

	if (count > 1)
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		(*stk)->next = temp;
	}
	ft_printf("s\n");
}
