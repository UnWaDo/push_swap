/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:12:13 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:16 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf.h"

int	is_sorted(t_stack *stack)
{
	int	v;

	if (stack == NULL || stack->next == NULL)
		return (1);
	v = stack->value;
	while (stack->next)
	{
		if (v > stack->next->value)
			return (0);
		v = stack->next->value;
		stack = stack->next;
	}
	return (1);
}

int	should_roll_up(t_stack *s, t_stack *target)
{
	t_stack	*mv;

	mv = target;
	while (s != target && mv)
	{
		s = s->next;
		mv = mv->next;
	}
	if (s == target)
		return (1);
	else
		return (0);
}

int	count_rolls(t_stack *s, t_stack *target)
{
	int		up;
	int		down;
	t_stack	*mv;

	mv = target;
	up = 0;
	down = 0;
	while (s != target && mv)
	{
		s = s->next;
		mv = mv->next;
		up++;
		down++;
	}
	if (s == target)
		return (down);
	return (up);
}

t_stack	*locate_insertion_pos(t_stack *s, t_stack *target)
{
	t_stack	*min_s;
	t_stack	*max_s;

	min_s = find_min_element(s);
	max_s = find_max_element(s);
	if (max_s == NULL)
		return (NULL);
	if (target->value > max_s->value)
		return (min_s);
	while (min_s && min_s->value < target->value)
		min_s = min_s->next;
	if (min_s == NULL)
	{
		min_s = s;
		while (min_s && min_s->value < target->value)
			min_s = min_s->next;
	}
	return (min_s);
}

void	count_rotations(t_stack *a, t_stack *b)
{
	t_stack	*cur;
	t_stack	*ins;

	cur = b;
	while (cur)
	{
		ins = locate_insertion_pos(a, cur);
		cur->rotations = count_rolls(a, ins) + count_rolls(b, cur);
		cur = cur->next;
	}
}
