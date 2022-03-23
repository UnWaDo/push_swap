#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

int	get_command(int fd)
{
	int		cmd;
	int		len;
	char	*line;

	line = get_next_line(fd);
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

void	execute_command(t_stack **a, t_stack **b, int cmd)
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
