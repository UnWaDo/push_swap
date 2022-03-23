/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:19:38 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 16:54:18 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	swap(t_stack **s)
{
	t_stack	*next;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	next = (*s)->next;
	(*s)->next = next->next;
	next->next = *s;
	*s = next;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	last = *s;
	while (last->next)
		last = last->next;
	first = *s;
	*s = first->next;
	last->next = first;
	first->next = NULL;
}

void	rrotate(t_stack **s)
{
	t_stack	*pre_last;
	t_stack	*last;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	pre_last = *s;
	while (pre_last->next)
	{
		last = pre_last->next;
		if (last->next == NULL)
			break ;
		pre_last = last;
	}
	pre_last->next = NULL;
	last->next = *s;
	*s = last;
}
