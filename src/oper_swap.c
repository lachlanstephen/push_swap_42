/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:35:54 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/27 23:47:39 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_elem_a(t_list **stk, int count)
{
	t_list	*temp;

	if (count > 1)
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		(*stk)->next = temp;
	}
	ft_printf("sa\n");
}

void	ft_swap_elem_b(t_list **stk, int count)
{
	t_list	*temp;

	if (count > 1)
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		(*stk)->next = temp;
	}
	ft_printf("sb\n");
}
