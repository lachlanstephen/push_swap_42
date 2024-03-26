/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:01:53 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/25 03:04:15 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_push_swap(t_list *stack_a, int count_a, int count_b)
{
	int		lim;
	int		idx;
	int		step;
	t_list	*stack_b;

	stack_b = NULL;
	idx = -1;
	step = -1;
	ft_remap_list(stack_a, count_a);
	lim = ft_index_limit(count_a);
	while (++idx < lim)
	{
		step = -1;
		while (stack_a != NULL && ++step < count_a)
		{
			if ((stack_a->content >> idx) & 1)
				stack_a = ft_rot_elem_a(stack_a, count_a);
			else if (step-- >= -1)
				ft_push_b(&stack_a, &stack_b, &count_a, &count_b);
		}
		step = -1;
		while (idx + 1 < lim && stack_b != NULL && ++step < count_b)
		{
			if (((stack_b->content >> (idx + 1)) & 1) && step-- >= -1)
				ft_push_a(&stack_b, &stack_a, &count_b, &count_a);
			else
				stack_b = ft_rot_elem_b(stack_b, count_b);
		}
	}
	while (stack_b != NULL && count_b > 0)
		ft_push_a(&stack_b, &stack_a, &count_b, &count_a);
	return (stack_a);
}
