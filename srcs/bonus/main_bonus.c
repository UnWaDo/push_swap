#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

#define CMD_END_OK	0b1
#define CMD_A		0b10
#define CMD_B		0b100
#define CMD_PUSH	0b1000
#define CMD_RROTATE	0b10000
#define CMD_ROTATE	0b100000
#define CMD_SWAP	0b1000000
#define CMD_AVAIL	"sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n"

static int	get_command(void)
{
	int		cmd;
	int		len;
	char	*line;

	line = get_next_line(0);
	if (line == NULL)
		return (CMD_END_OK);
	len = ft_strlen(line);
	if (len < 3 || line[len - 1] != '\n'
		|| ft_strnstr(CMD_AVAIL, line, ft_strlen(CMD_AVAIL)) == NULL)
	{
		free(line);
		return (0);
	}
	cmd = CMD_SWAP >> ('s' - line[0]);
	cmd |= CMD_A << (line[len - 2] != 'a');
	cmd |= CMD_A * (line[len - 2] == 'r' || line[len - 2] == 's');
	if (line[0] == 'r' && line[1] == 'r' && line[2] != '\n')
		cmd = ((cmd & (~CMD_ROTATE)) | CMD_RROTATE);
	free(line);
	return (cmd);
}

static void	execute_command(t_stack **a, t_stack **b, int cmd)
{
	static	void	(*operation[])(t_stack **) = \
		{&rrotate, &rotate, &swap};

	if (cmd & CMD_PUSH)
	{
		if (cmd & CMD_A)
			push(b, a);
		else
			push(a, b);
	}
	else
	{
		if (cmd & CMD_A)
			operation[cmd >> 5](a);
		if (cmd & CMD_B)
			operation[cmd >> 5](b);
	}
}

static void	exit_failure(t_stack **a, t_stack **b)
{
	ft_printf("Error\n");
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}

static void	exit_success(t_stack **a, t_stack **b, int is_sorted)
{
	if (is_sorted)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(a);
	stack_clear(b);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		cmd;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a = read_stack(argc - 1, argv + 1);
	stack_b = NULL;
	if (stack_a == NULL)
		exit_failure(&stack_a, &stack_b);
	cmd = get_command();
	while (cmd && (cmd & (~CMD_END_OK)))
	{
		execute_command(&stack_a, &stack_b, cmd);
		cmd = get_command();
	}
	if (cmd == 0)
		exit_failure(&stack_a, &stack_b);
	exit_success(&stack_a, &stack_b, !stack_b && is_sorted(stack_a));
}
