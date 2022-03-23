#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define CMD_END_OK 	0b1
# define CMD_A			0b10
# define CMD_B			0b100
# define CMD_PUSH		0b1000
# define CMD_RROTATE	0b10000
# define CMD_ROTATE		0b100000
# define CMD_SWAP		0b1000000
# define CMD_AVAIL		"sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n"

int		get_command(int fd);
void	execute_command(t_stack **a, t_stack **b, int cmd);
void	exit_success(t_stack **a, t_stack **b, int is_sorted);
void	exit_failure(t_stack **a, t_stack **b);

#endif
