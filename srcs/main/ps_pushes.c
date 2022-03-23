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

static void	perform_rotations(int ra, int rb)
{
	static char	*ra_str[3] = {"", "ra\n", "rra\n"};
	static char	*rb_str[3] = {"", "rb\n", "rrb\n"};

	while (ra || rb)
	{
		if (ra > 0 && rb > 0)
			ft_printf("rr\n");
		else if (ra < 0 && rb < 0)
			ft_printf("rrr\n");
		else
		{
			ft_printf(ra_str[((((unsigned int) ra) >> 31) + 1) *(ra != 0)]);
			ft_printf(rb_str[((((unsigned int) rb) >> 31) + 1) *(rb != 0)]);
		}
		ra += (ra < 0) - (ra > 0);
		rb += (rb < 0) - (rb > 0);
	}
}

void	store_rotations(int cmd)
{
	static int	ra;
	static int	rra;
	static int	rb;
	static int	rrb;

	if (cmd & MAKE_ROTATIONS)
	{
		perform_rotations(ra - rra, rb - rrb);
		cmd |= CLEAN_ROTATIONS;
	}
	ra = ra * (1 - ((cmd & CLEAN_ROTATIONS) > 0)) + ((cmd & ADD_RA) > 0);
	rra = rra * (1 - ((cmd & CLEAN_ROTATIONS) > 0)) + ((cmd & ADD_RRA) > 0);
	rb = rb * (1 - ((cmd & CLEAN_ROTATIONS) > 0)) + ((cmd & ADD_RB) > 0);
	rrb = rrb * (1 - ((cmd & CLEAN_ROTATIONS) > 0)) + ((cmd & ADD_RRB) > 0);
}

void	pa(t_stack **a, t_stack **b)
{
	store_rotations(MAKE_ROTATIONS);
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	store_rotations(MAKE_ROTATIONS);
	ft_printf("pb\n");
	push(a, b);
}
