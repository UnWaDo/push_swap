#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "push_swap.h"
#include "push_swap_bonus.h"

static void	output_stacks(t_stack *a, t_stack *b)
{
	ft_printf("\e[1;1H\e[2J");
	ft_printf("%8s%8s\n", "a", "b");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%8d", a->value);
			a = a->next;
		}
		else
			ft_printf("%8s", "");
		if (b)
		{
			ft_printf("%8d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
}

static void	read_commands(t_stack **a, t_stack **b, int fd)
{
	int		count;
	int		cmd;
	char	*line;

	count = 0;
	output_stacks(*a, *b);
	ft_printf("commands used: %d\n", count);
	line = get_next_line(0);
	while (line && ft_strncmp(line, "exit\n", 5))
	{
		cmd = get_command(fd);
		if (cmd & CMD_END_OK)
			break ;
		count++;
		execute_command(a, b, cmd);
		output_stacks(*a, *b);
		ft_printf("commands used: %d\n", count);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		fd;

	if (argc < 3)
	{
		ft_printf("Usage: visualize file_with_commands *stack*\n");
		exit(EXIT_FAILURE);
	}
	stack_a = read_stack(argc - 2, argv + 2);
	stack_b = NULL;
	if (stack_a == NULL)
		exit_failure(&stack_a, &stack_b);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_failure(&stack_a, &stack_b);
	read_commands(&stack_a, &stack_b, argv[1]);
	close(fd);
	exit_success(&stack_a, &stack_b, !stack_b && is_sorted(stack_a));
}
