/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:05:43 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/21 16:00:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/*
void	*ft_del_content(t_list *lst)
{
	lst->content = 0;
}
*/

int	ft_atol_ps(char *str)
{
	long	res;
	int		i;
	bool	neg;

	i = -1;
	res = 0;
	neg = false;
	if (str[0] == '-' && i++)
		neg = true;
	while (str[++i] != 0)
	{
		if (str[i] > '9' || str[i] < '0')
			ft_error();
		res *= 10;
		res += str[i] - '0';
	}
	if (neg == true)
		res *= -1;
	if (res > INT_MAX || res < INT_MIN)
		ft_error();
	return (res);
}
