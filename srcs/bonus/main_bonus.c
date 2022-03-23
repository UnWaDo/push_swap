/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:54:06 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:06 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "push_swap_bonus.h"

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
	cmd = get_command(0);
	while (cmd && (cmd & (~CMD_END_OK)))
	{
		execute_command(&stack_a, &stack_b, cmd);
		cmd = get_command(0);
	}
	if (cmd == 0)
		exit_failure(&stack_a, &stack_b);
	exit_success(&stack_a, &stack_b, !stack_b && is_sorted(stack_a));
}
