/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:19:39 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:26 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = read_stack(argc - 1, argv + 1);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}
