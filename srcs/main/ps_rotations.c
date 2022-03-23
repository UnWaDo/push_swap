/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:09:33 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:33 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ra(t_stack **a, t_stack **b)
{
	(void) b;
	store_rotations(ADD_RA);
	rotate(a);
}

void	rb(t_stack **a, t_stack **b)
{
	(void) a;
	store_rotations(ADD_RB);
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	store_rotations(ADD_RA | ADD_RB);
	rotate(a);
	rotate(b);
}
