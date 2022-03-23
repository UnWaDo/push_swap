/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:09:53 by lalex             #+#    #+#             */
/*   Updated: 2022/03/10 10:52:18 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	sa(t_stack **a, t_stack **b)
{
	(void) b;
	store_rotations(MAKE_ROTATIONS);
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_stack **a, t_stack **b)
{
	(void) a;
	store_rotations(MAKE_ROTATIONS);
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	store_rotations(MAKE_ROTATIONS);
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
