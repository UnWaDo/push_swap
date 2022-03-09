/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:19:39 by lalex             #+#    #+#             */
/*   Updated: 2022/03/09 21:21:38 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

t_stack	*read_input(int len, char **values)
{
	t_stack	*stack;
	t_stack	*new;
	int		v;

	stack = NULL;
	new = NULL;
	while (len--)
	{
		v = ft_atoi(values[len]);
		new = stack_new(v);
		if (new == NULL)
			break ;
		stack_append(&stack, new);
	}
	if (new == NULL)
		stack_clear(&stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = read_input(argc - 1, argv + 1);
	if (stack_a == NULL)
		exit(EXIT_FAILURE);
	stack_b = NULL;
	if (is_sorted(stack_a))
		ft_printf("Sorted\n");
	else
		ft_printf("Unsorted\n");
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}