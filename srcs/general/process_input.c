/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:54:12 by lalex             #+#    #+#             */
/*   Updated: 2022/03/23 17:50:21 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

int	is_value_valid(char *value, int *result, t_stack *stack)
{
	long	v;
	char	*l;

	v = ft_strtol(value, &l, 10);
	if (v > INT_MAX || v < INT_MIN)
		return (0);
	if (*l != '\0')
		return (0);
	if (locate_value(stack, v) != NULL)
		return (0);
	*result = (int) v;
	return (1);
}

static int	read_argument(char *arg, t_stack **s)
{
	t_stack	*new;
	int		v;

	if (!is_value_valid(arg, &v, *s))
		return (-1);
	new = stack_new(v);
	if (new == NULL)
		return (-1);
	stack_append(s, new);
	return (0);
}

static void	clear_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	args_len(char **strings)
{
	int	len;

	len = 0;
	while (strings[len])
		len++;
	return (len);
}

t_stack	*read_stack(int len, char **values)
{
	t_stack	*stack;
	int		status;
	char	**splitted;
	int		splt_len;

	stack = NULL;
	status = 0;
	while (len-- && status == 0)
	{
		status = -1;
		splitted = ft_split(values[len], ' ');
		if (!splitted)
			break ;
		splt_len = args_len(splitted);
		while (splt_len--)
			status = read_argument(splitted[splt_len], &stack);
		clear_strings(splitted);
	}
	if (status != 0)
		stack_clear(&stack);
	return (stack);
}
