#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

void	exit_failure(t_stack **a, t_stack **b)
{
	ft_printf("Error\n");
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}

void	exit_success(t_stack **a, t_stack **b, int is_sorted)
{
	if (is_sorted)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_SUCCESS);
}
