#include "push_swap.h"
#include <stdlib.h>
#include "push_swap_sorter.h"

void	make_first_in_a(t_stack **a, t_stack **b, t_stack *target)
{
	if (should_roll_up(*a, target))
	{
		while (*a != target)
			ra(a, b);
	}
	else
	{
		while (*a != target)
			rra(a, b);
	}
}

void	make_first_in_b(t_stack **a, t_stack **b, t_stack *target)
{
	if (should_roll_up(*b, target))
	{
		while (*b != target)
			rb(a, b);
	}
	else
	{
		while (*b != target)
			rrb(a, b);
	}
}

void	make_rolling(t_stack **a, t_stack **b)
{
	t_stack	*min_r;
	t_stack	*iter;

	count_rotations(*a, *b);
	min_r = *b;
	iter = *b;
	while (iter)
	{
		if (min_r->rotations > iter->rotations)
			min_r = iter;
		iter = iter->next;
	}
	make_first_in_b(a, b, min_r);
	make_first_in_a(a, b, locate_insertion_pos(*a, min_r));
}
