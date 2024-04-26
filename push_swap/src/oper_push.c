/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:34:00 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 23:00:24 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_b(t_list **stk_a, t_list **stk_b, int *c_a, int *c_b)
{
	t_list	*temp;

	temp = *stk_a;
	if (*c_a > 0)
	{
		temp = (*stk_a)->next;
		ft_lstadd_front(stk_b, (*stk_a));
		(*c_a)--;
		(*c_b)++;
		ft_printf("pb\n");
	}
	(*stk_a) = temp;
}

void	ft_push_a(t_list **stk_b, t_list **stk_a, int *c_b, int *c_a)
{
	t_list	*temp;

	temp = *stk_b;
	if (*c_b > 0)
	{
		temp = (*stk_b)->next;
		ft_lstadd_front(stk_a, (*stk_b));
		(*c_b)--;
		(*c_a)++;
		ft_printf("pa\n");
	}
	(*stk_b) = temp;
}
