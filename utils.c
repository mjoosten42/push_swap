/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:19:37 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 14:37:14 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_long_atoi(const char *str)
{
	long	result;
	int		min;

	if (ft_strlen(str) > 11)
		ft_error();
	str = (char *)str;
	while (ft_isspace(*str))
		str++;
	min = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min++;
		str++;
	}
	result = 0;
	while (ft_isdigit(*str))
		result = 10 * result + *str++ - '0';
	if (min)
		result = -result;
	if (result < INT_MIN || result > INT_MAX)
		ft_error();
	return (result);
}

int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
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

int	ft_amount_lower(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->number < number)
			i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_remainder_issorted(t_stack *a, int bits, int remainder)
{
	while (remainder--)
	{
		if ((a->number >> bits) % 2)
			return (0);
		a = a->next;
	}
	return (1);
}
