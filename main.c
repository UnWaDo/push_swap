/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:19:39 by lalex             #+#    #+#             */
/*   Updated: 2022/03/10 11:44:34 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	is_value_valid(char *value, int *result)
{
	long	v;
	char	*l;

	v = ft_strtol(value, &l, 10);
	if (v > INT_MAX || v < INT_MIN)
		return (0);
	if (*l != '\0')
		return (0);
	*result = (int) v;
	return (1);
}

t_stack	*read_input(int len, char **values)
{
	t_stack	*stack;
	t_stack	*new;
	int		v;

	stack = NULL;
	while (len--)
	{
		new = NULL;
		if (!is_value_valid(values[len], &v))
			break ;
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
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	rrotate(&stack_a);
	ft_printf("stack a:\n");
	stack_output(stack_a);
	ft_printf("stack b:\n");
	stack_output(stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	exit(EXIT_SUCCESS);
}