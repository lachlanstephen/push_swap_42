/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:08:07 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/27 23:23:36 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_med_fill_a(t_list *stack_a, t_list *stack_b, int c_a, int c_b)
{
	while (stack_b != NULL && c_b > 0)
	{
		ft_push_a(&stack_b, &stack_a, &c_b, &c_a);
		if (c_b == 1)
			stack_a = ft_rot_elem_a(stack_a, c_a);
	}
	return (stack_a);
}

t_list	*ft_cmp_fill_a(t_list *stack_a, t_list *stack_b, int c_a, int c_b)
{
	while (stack_b != NULL && c_b > 0)
		ft_push_a(&stack_b, &stack_a, &c_b, &c_a);
	return (stack_a);
}

void	ft_initialise_vals(int (*iter)[3], int c_a)
{
	(*iter)[1] = -1;
	(*iter)[0] = ft_index_limit(c_a);
}
