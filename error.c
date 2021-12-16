/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:19:37 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/16 14:22:58 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_checknumber(t_stack *stack, char *str)
{
	int	number;

	number = ft_atoi(str);
	while (stack)
	{
		if (stack->number == number)
			ft_error();
		stack = stack->next;
	}
	if (!ft_isdigit(*str) && *str != '-')
		ft_error();
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		str++;
	}
	return (0);
}
