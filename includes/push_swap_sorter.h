/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:54:56 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:56 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORTER_H
# define PUSH_SWAP_SORTER_H

# include "push_swap.h"

void	make_rolling(t_stack **a, t_stack **b);
void	make_first_in_a(t_stack **a, t_stack **b, t_stack *target);
void	make_first_in_b(t_stack **a, t_stack **b, t_stack *target);

#endif
