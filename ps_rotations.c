/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:09:33 by lalex             #+#    #+#             */
/*   Updated: 2022/03/09 21:18:13 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void ra(t_stack *a, t_stack *b)
{
	(void) b;
	ft_printf("ra\n");
	rotate(a);
}

void rb(t_stack *a, t_stack *b)
{
	(void) a;
	ft_printf("rb\n");
	rotate(b);
}

void rs(t_stack *a, t_stack *b)
{
	ft_printf("rs\n");
	rotate(a);
	rotate(b);
}
