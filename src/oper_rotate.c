/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:34:18 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/25 02:35:24 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_rot_elem_a(t_list *stk, int c_a)
{
	t_list	*head;
	t_list	*top;

	head = stk;
	if (c_a > 1)
	{
		top = stk->next;
		while (stk != NULL && stk->next != NULL)
			stk = stk->next;
		stk->next = head;
		head->next = NULL;
		ft_printf("ra\n");
		return (top);
	}
	return (head);
}

t_list	*ft_rot_elem_b(t_list *stk, int c_b)
{
	t_list	*head;
	t_list	*top;

	head = stk;
	if (c_b > 1)
	{
		top = stk->next;
		while (stk != NULL && stk->next != NULL)
			stk = stk->next;
		stk->next = head;
		head->next = NULL;
		ft_printf("rb\n");
		return (top);
	}
	return (head);
}

t_list	*ft_rev_rot_elem_a(t_list *stk, int c_a)
{
	t_list	*head;
	t_list	*prev;

	head = stk;
	if (c_a > 1)
	{
		while (stk != NULL && stk->next != NULL)
		{
			prev = stk;
			stk = stk->next;
		}
		stk->next = head;
		prev->next = NULL;
		ft_printf("rra\n");
		return (stk);
	}
	return (head);
}

t_list	*ft_rev_rot_elem_b(t_list *stk, int c_b)
{
	t_list	*head;
	t_list	*prev;

	head = stk;
	if (c_b > 1)
	{
		while (stk != NULL && stk->next != NULL)
		{
			prev = stk;
			stk = stk->next;
		}
		stk->next = head;
		prev->next = NULL;
		ft_printf("rrb\n");
		return (stk);
	}
	return (head);
}
