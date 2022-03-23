/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:54:40 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:40 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "push_swap_sorter.h"

static void	sort_three(t_stack **a, t_stack **b)
{
	t_stack	*min_a;
	t_stack	*max_a;

	if (is_sorted(*a))
		return ;
	min_a = find_min_element(*a);
	max_a = find_max_element(*a);
	if (*a == min_a)
		sa(a, b);
	else if (*a == max_a)
	{
		if (max_a->next == min_a)
			ra(a, b);
		else
			sa(a, b);
	}
	else
	{
		if (max_a->next == min_a)
			rra(a, b);
		else
			sa(a, b);
	}
	sort_three(a, b);
}

static void	sort_to_five(t_stack **a, t_stack **b)
{
	int	am;
	int	i;

	if (is_sorted(*a))
		return ;
	am = count_stack(*a) - 3;
	i = 0;
	while (i < am)
	{
		pb(a, b);
		i++;
	}
	sort_three(a, b);
	i = 0;
	while (i < am)
	{
		make_rolling(a, b);
		pa(a, b);
		i++;
	}
	make_first_in_a(a, b, find_min_element(*a));
}

static void	sort_iteration(t_stack **a, t_stack **b, int q, int am)
{
	t_stack	*min_a;
	int		border;

	min_a = find_min_element(*a);
	if (am <= 250)
		border = am / 2 * q;
	else if (am <= 750)
		border = (am / 4) * q;
	else
		border = (am / 8) * q;
	while (min_a && min_a->index < border)
	{
		if ((*a)->index < border)
			pb(a, b);
		else
			ra(a, b);
		if (*b == min_a)
			min_a = find_min_element(*a);
	}
	if (!is_sorted(*a))
		sort_iteration(a, b, q + 1, am);
}

static void	quick_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_a;
	int		am;

	normalize_values(*a);
	am = count_stack(*a);
	sort_iteration(a, b, 1, am);
	while (*b)
	{
		make_rolling(a, b);
		pa(a, b);
	}
	min_a = find_min_element(*a);
	make_first_in_a(a, b, min_a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	count;

	if (is_sorted(*a))
		return ;
	store_rotations(CLEAN_ROTATIONS);
	count = count_stack(*a);
	if (count == 2)
		sa(a, b);
	else if (count <= 5)
		sort_to_five(a, b);
	else
		quick_sort(a, b);
	store_rotations(MAKE_ROTATIONS);
}
