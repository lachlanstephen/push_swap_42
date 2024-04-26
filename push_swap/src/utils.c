/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:05:43 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/29 22:04:48 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_index_limit(int num)
{
	if (num <= 1)
		return (1);
	else
		return (1 + ft_index_limit(num / 2));
}

void	ft_free_list(t_list *lst, int exit)
{
	t_list	*next;

	while (lst != NULL && lst->next != NULL)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	free(lst);
	if (exit == 1)
		ft_error();
}

int	ft_atol_ps(char *str, t_list *lst)
{
	long	res;
	int		i;
	bool	neg;

	i = -1;
	res = 0;
	neg = false;
	if (str[0] == '-' && ++i > -1)
		neg = true;
	while (str[++i] != 0)
	{
		if (str[i] > '9' || str[i] < '0')
			ft_free_list(lst, 1);
		res *= 10;
		res += str[i] - '0';
	}
	if (neg == true)
		res *= -1;
	if (res > INT_MAX || res < INT_MIN)
		ft_free_list(lst, 1);
	return (res);
}
