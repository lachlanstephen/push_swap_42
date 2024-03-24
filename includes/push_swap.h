/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:18:15 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/24 23:18:42 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "../libft/includes/libft.h"

int			ft_atol_ps(char *str);
int			ft_index_limit(int num);

t_list		*ft_push_swap(t_list *stack_a, int count_a);

//void		*ft_del_content(t_list *lst);
void		ft_error(void);
void		ft_free_list(t_list *lst);
void		ft_remap_list(t_list *lst, int count);
void		ft_remap_values(t_list *lst, int *nums, int count);

#endif
