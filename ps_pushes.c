/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:09:59 by lalex             #+#    #+#             */
/*   Updated: 2022/03/10 10:51:49 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}
