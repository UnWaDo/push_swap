/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:12:13 by lalex             #+#    #+#             */
/*   Updated: 2022/03/09 21:17:10 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_sorted(t_stack *stack)
{
	int	v;

	if (stack == NULL || stack->next == NULL)
		return (1);
	v = stack->value;
	while (stack->next)
	{
		if (v > stack->next->value)
			return (0);
		v = stack->next->value;
		stack = stack->next;
	}
	return (1);
}