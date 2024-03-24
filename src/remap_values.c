/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remap_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:21:02 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/25 01:37:59 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_partition(int *nums, int start, int end)
{
	int	i;
	int	j;
	int	temp;
	int	pivot;

	pivot = nums[end];
	j = start - 1;
	i = start - 1;
	while (++j < end)
	{
		if (nums[j] < pivot)
		{
			temp = nums[++i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	nums[j] = nums[++i];
	nums[i] = pivot;
	return (i);
}

void	ft_quicksort(int *nums, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = ft_partition(nums, start, end);
	ft_quicksort(nums, start, pivot - 1);
	ft_quicksort(nums, pivot + 1, end);
}

void	ft_remap_values(t_list *lst, int *nums, int count)
{
	int	i;

	while (lst != NULL)
	{
		i = -1;
		while (++i < count)
		{
			if (lst->content == nums[i])
			{
				lst->content = i;
				break ;
			}
		}
		lst = lst->next;
	}
}

void	ft_remap_list(t_list *lst, int count)
{
	int		*nums;
	int		i;
	t_list	*head;

	i = -1;
	head = lst;
	nums = malloc(sizeof(int) * count);
	if (nums == NULL)
	{
		ft_free_list(lst);
		ft_error();
	}
	while (lst != NULL && ++i < count)
	{
		nums[i] = lst->content;
		lst = lst->next;
	}
	ft_quicksort(nums, 0, count - 1);
	ft_remap_values(head, nums, count);
	free(nums);
}
