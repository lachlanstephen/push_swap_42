/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:17:27 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 23:33:35 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_dupe(t_list *stk, int val)
{
	while (stk != NULL)
	{
		if (stk->content == val)
			return (true);
		stk = stk->next;
	}
	return (false);
}

bool	check_unsorted(t_list *stk)
{
	int	prev;

	if (stk != NULL)
		prev = stk->content;
	else
		exit(1);
	stk = stk->next;
	while (stk != NULL)
	{
		if (stk->content < prev)
			return (true);
		prev = stk->content;
		stk = stk->next;
	}
	return (false);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*temp;
	int		count[2];

	if (argc <= 1)
		exit(1);
	count[0] = argc - 1;
	count[1] = 0;
	stack_a = NULL;
	while (--argc >= 1)
	{
		temp = ft_lstnew(ft_atol_ps(argv[argc], stack_a));
		if (ft_dupe(stack_a, temp->content))
		{
			ft_free_list(temp, 0);
			ft_free_list(stack_a, 1);
		}
		ft_lstadd_front(&stack_a, temp);
	}
	if (check_unsorted(stack_a))
		stack_a = ft_push_swap(stack_a, count[0], count[1]);
	ft_free_list(stack_a, 0);
	return (0);
}
