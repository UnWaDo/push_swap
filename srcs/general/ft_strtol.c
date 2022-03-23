/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:29:29 by lalex             #+#    #+#             */
/*   Updated: 2022/03/10 11:39:52 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

long	ft_strtol(const char *str, char **endptr, int base)
{
	long long	res;
	long long	new_value;
	int			mltp;

	while (ft_isspace(*str) && *str)
		str++;
	mltp = 1;
	if (*str == '-')
		mltp = -1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		new_value = res * base + mltp * (*str - '0');
		if (mltp < 0 && new_value > res)
			return (0);
		if (mltp > 0 && new_value < res)
			return (-1);
		res = new_value;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *) str;
	return ((long) res);
}
