#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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

static void	output_stacks(t_stack *a, t_stack *b)
{
	ft_printf("%4s%4s\n", "a", "b");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%4d", a->value);
			a = a->next;
		}
		else
			ft_printf("%4s", "");
		if (b)
		{
			ft_printf("%4d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	char	c;
	int		fd;
	int		count;

	if (argc < 3)
	{
		ft_printf("Usage: visual file_with_commands *stack*\n");
		exit(EXIT_FAILURE);
	}
	stack_a = read_stack(argc - 2, argv + 2);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		stack_clear(&stack_a);
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	c = ' ';
	count = 0;
	while (c != 'e')
	{
		ft_printf("\e[1;1H\e[2J");
		output_stacks(stack_a, stack_b);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("commands used: %d\n", count);
		ft_printf("next command: %s\n", line);
		if (execute_command(&stack_a, &stack_b, line))
			ft_printf("Invalid command: %s\n", line);
		count++;
		free(line);
		read(1, &c, 1);
	}
	if (stack_b || is_sorted(stack_a) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	close(fd);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}
