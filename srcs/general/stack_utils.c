/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:19:34 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:22 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

void	stack_output(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof (*new));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	stack_append(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

void	stack_clear(t_stack **stack)
{
	t_stack	*el;
	t_stack	*next;

	el = *stack;
	while (el)
	{
		next = el->next;
		free(el);
		el = next;
	}
	*stack = NULL;
}

t_stack	*locate_value(t_stack *stack, int value)
{
	while (stack && stack->value != value)
		stack = stack->next;
	return (stack);
}
