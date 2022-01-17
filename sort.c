/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:42:25 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/17 14:56:15 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bits;

	bits = 0;
	while (bits < 32)
	{
		size = ft_stacksize(*a);
		while (size--)
		{
			if (ft_remainder_issorted(*a, bits, size + 1))
				continue ;
			if (((*a)->number >> bits) % 2)
				ra(a, b);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		bits++;
	}
	exit(EXIT_SUCCESS);
}

void	ft_sortthree(t_stack **a, t_stack **b)
{
	if ((*a)->number == 0)
	{
		rra(a, b);
		sa(a, b);
		exit(EXIT_SUCCESS);
	}
	if ((*a)->number == 1)
	{
		if ((*a)->next->number == 0)
			sa(a, b);
		else
			rra(a, b);
		exit(EXIT_SUCCESS);
	}
	ra(a, b);
	if ((*a)->number == 1)
		sa(a, b);
	exit(EXIT_SUCCESS);
}

void	ft_sortfive(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}
