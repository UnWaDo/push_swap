#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	is_value_valid(char *value, int *result, t_stack *stack)
{
	long	v;
	char	*l;

	v = ft_strtol(value, &l, 10);
	if (v > INT_MAX || v < INT_MIN)
		return (0);
	if (*l != '\0')
		return (0);
	if (locate_value(stack, v) != NULL)
		return (0);
	*result = (int) v;
	return (1);
}

t_stack	*read_stack(int len, char **values)
{
	t_stack	*stack;
	t_stack	*new;
	int		v;

	stack = NULL;
	while (len--)
	{
		new = NULL;
		if (!is_value_valid(values[len], &v, stack))
			break ;
		new = stack_new(v);
		if (new == NULL)
			break ;
		stack_append(&stack, new);
	}
	if (new == NULL)
		stack_clear(&stack);
	return (stack);
}
