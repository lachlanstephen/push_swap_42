/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:01:53 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 23:11:56 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*ft_small_sort(t_list *stack_a, int c_a)
{
	t_list	*last;

	while (check_unsorted(stack_a))
	{
		last = ft_lstlast(stack_a);
		if (stack_a->content > last->content)
			stack_a = ft_rot_elem_a(stack_a, c_a);
		else if (stack_a->content > stack_a->next->content)
			ft_swap_elem_a(&stack_a, c_a);
		else
			stack_a = ft_rev_rot_elem_a(stack_a, c_a);
	}
	return (stack_a);
}

static void	ft_set_limit(t_list *stack_a, int *smallest, int *largest)
{
	*smallest = stack_a->content;
	*largest = stack_a->content;
	while (stack_a != NULL)
	{
		if (stack_a->content < *smallest)
			*smallest = stack_a->content;
		if (stack_a->content > *largest)
			*largest = stack_a->content;
		stack_a = stack_a->next;
	}
}

static t_list	*ft_medium_sort(t_list *stack_a, t_list *stack_b,
	int c_a, int c_b)
{
	int		smallest;
	int		largest;
	int		init_count;

	ft_set_limit(stack_a, &smallest, &largest);
	init_count = c_a;
	while (stack_a != NULL && c_a > 3)
	{
		if (stack_a->content == smallest)
		{
			ft_push_b(&stack_a, &stack_b, &c_a, &c_b);
			if (c_a == 3)
				ft_swap_elem_b(&stack_b, c_b);
		}
		else if (stack_a->content == largest && init_count == 5)
			ft_push_b(&stack_a, &stack_b, &c_a, &c_b);
		else
			stack_a = ft_rot_elem_a(stack_a, c_a);
	}
	stack_a = ft_small_sort(stack_a, c_a);
	stack_a = ft_med_fill_a(stack_a, stack_b, c_a, c_b);
	return (stack_a);
}

/*
int iter[3] - holds the iterators and limits used in the function
iter[0] = limit : the power of 2 up to which the numbers need to be converted to
their binary format
iter[1] = index : the current power of 2 for which we are doing binary comparison
iter[2] = step : the depth we have traversed into the list, essentially checking
how many of the list items we've done comparisons on
*/
static t_list	*ft_complex_sort(t_list *stack_a, t_list *stack_b,
	int c_a, int c_b)
{
	int	iter[3];

	ft_remap_list(stack_a, c_a);
	ft_initialise_vals(&iter, c_a);
	while (++(iter[1]) < iter[0])
	{
		iter[2] = -1;
		while (stack_a != NULL && ++(iter[2]) < c_a)
		{
			if ((stack_a->content >> (iter[1])) & 1)
				stack_a = ft_rot_elem_a(stack_a, c_a);
			else if ((iter[2])-- >= -1)
				ft_push_b(&stack_a, &stack_b, &c_a, &c_b);
		}
		iter[2] = -1;
		while (iter[1] + 1 < iter[0] && stack_b != NULL && ++(iter[2]) < c_b)
		{
			if (((stack_b->content >> (iter[1] + 1)) & 1) && (iter[2])-- >= -1)
				ft_push_a(&stack_b, &stack_a, &c_b, &c_a);
			else
				stack_b = ft_rot_elem_b(stack_b, c_b);
		}
	}
	stack_a = ft_cmp_fill_a(stack_a, stack_b, c_a, c_b);
	return (stack_a);
}

t_list	*ft_push_swap(t_list *stack_a, int count_a, int count_b)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (count_a <= 3)
		stack_a = ft_small_sort(stack_a, count_a);
	else if (count_a <= 5)
		stack_a = ft_medium_sort(stack_a, stack_b, count_a, count_b);
	else
		stack_a = ft_complex_sort(stack_a, stack_b, count_a, count_b);
	return (stack_a);
}
