/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:01:53 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/25 01:37:28 by darkwater        ###   ########.fr       */
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
	}
	(*stk_a) = temp;
	ft_printf("pb\n");
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
	}
	(*stk_b) = temp;
	ft_printf("pa\n");
}

t_list	*ft_rot_elem_a(t_list *stk, int c_a)
{
	t_list	*head;
	t_list	*top;

	head = stk;
	if (c_a != 1)
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
	if (c_b != 1)
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

t_list	*ft_rev_rot_elem(t_list *stk)
{
	t_list	*head;
	t_list	*prev;

	head = stk;
	while (stk != NULL && stk->next != NULL)
	{
		prev = stk;
		stk = stk->next;
	}
	stk->next = head;
	prev->next = NULL;
	ft_printf("rr\n");
	return (stk);
}

t_list	*ft_push_swap(t_list *stack_a, int count_a)
{
	int		lim;
	int		idx;
	int		step;
	t_list	*stack_b;
	int		count_b;

	count_b = 0;
	stack_b = NULL;
	idx = -1;
	step = -1;
	ft_remap_list(stack_a, count_a);
	lim = ft_index_limit(count_a);
	while (++idx <= lim)
	{
		step = -1;
		while (stack_a != NULL && ++step < count_a)
		{
			if ((stack_a->content >> idx) & 1)
				stack_a = ft_rot_elem_a(stack_a, count_a);
			else 
			{
				ft_push_b(&stack_a, &stack_b, &count_a, &count_b);
				step--;
			}
		}
		step = -1;
		while (idx + 1 <= lim && stack_b != NULL && ++step < count_b)
		{
			if ((stack_b->content >> (idx + 1)) & 1)
			{
				ft_push_a(&stack_b, &stack_a, &count_b, &count_a);
				step--;
			}
			else
				stack_b = ft_rot_elem_b(stack_b, count_b);
		}
	}
	while (stack_b != NULL && count_b > 0)
		ft_push_a(&stack_b, &stack_a, &count_b, &count_a);
	return (stack_a);
}
