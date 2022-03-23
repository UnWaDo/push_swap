#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

static int	execute_command(t_stack **a, t_stack **b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		swap(a);
	else if (ft_strncmp(cmd, "sb\n", 4) == 0)
		swap(b);
	else if (ft_strncmp(cmd, "ss\n", 4) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(cmd, "pa\n", 4) == 0)
		push(b, a);
	else if (ft_strncmp(cmd, "pb\n", 4) == 0)
		push(a, b);
	else if (ft_strncmp(cmd, "ra\n", 4) == 0)
		rotate(a);
	else if (ft_strncmp(cmd, "rb\n", 4) == 0)
		rotate(b);
	else if (ft_strncmp(cmd, "rr\n", 4) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rrotate(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrotate(b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = read_stack(argc - 1, argv + 1);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (execute_command(&stack_a, &stack_b, line))
			break ;
		free(line);
		line = get_next_line(0);
	}
	if (line)
	{
		free(line);
		ft_printf("Error\n");
		stack_clear(&stack_a);
		stack_clear(&stack_b);
		exit(EXIT_FAILURE);
	}
	if (stack_b || is_sorted(stack_a) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}