/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:09:39 by lalex             #+#    #+#             */
/*   Updated: 2022/03/10 10:52:11 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	rra(t_stack **a, t_stack **b)
{
	(void) b;
	store_rotations(ADD_RRA);
	rrotate(a);
}

void	rrb(t_stack **a, t_stack **b)
{
	(void) a;
	store_rotations(ADD_RRB);
	rrotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	store_rotations(ADD_RRA | ADD_RRB);
	rrotate(a);
	rrotate(b);
}
