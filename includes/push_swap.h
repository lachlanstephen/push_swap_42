/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:18:15 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/21 16:20:40 by darkwater        ###   ########.fr       */
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

t_list		*ft_push_swap(t_list *stack_a, int count_a);

//void		*ft_del_content(t_list *lst);
void		ft_error(void);

#endif
