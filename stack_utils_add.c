#include "push_swap.h"

int	count_stack(t_stack *a)
{
	int	c;

	c = 0;
	while (a)
	{
		a = a->next;
		c++;
	}
	return (c);
}

t_stack	*find_max_element(t_stack *s)
{
	t_stack	*max;

	max = s;
	while (s)
	{
		if (s->value > max->value)
			max = s;
		s = s->next;
	}
	return (max);
}

t_stack	*find_min_element(t_stack *s)
{
	t_stack	*min;

	min = s;
	while (s)
	{
		if (s->value < min->value)
			min = s;
		s = s->next;
	}
	return (min);
}

void	normalize_values(t_stack *a)
{
	t_stack	*beginning;
	t_stack	*el;
	int		less_than;

	beginning = a;
	while (a)
	{
		less_than = 0;
		el = beginning;
		while (el)
		{
			less_than += (el->value < a->value);
			el = el->next;
		}
		a->index = less_than;
		a = a->next;
	}
}
