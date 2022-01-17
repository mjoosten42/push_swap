/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:42:25 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/17 16:46:45 by mjoosten         ###   ########.fr       */
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
}

void	ft_sortthree(t_stack **a, t_stack **b)
{
	if ((*a)->number == 0)
	{
		if ((*a)->next->number == 1)
			return ;
		rra(a, b);
		sa(a, b);
		return ;
	}
	if ((*a)->number == 1)
	{
		if ((*a)->next->number == 0)
			sa(a, b);
		else
			rra(a, b);
		return ;
	}
	ra(a, b);
	if ((*a)->number == 1)
		sa(a, b);
}

void	ft_sortfour(t_stack **a, t_stack **b)
{
	ft_movenumber(a, b, 3);
	ft_sortthree(a, b);
	pa(a, b);
	ra(a, b);
}

void	ft_sortfive(t_stack **a, t_stack **b)
{
	ft_movenumber(a, b, 3);
	ft_movenumber(a, b, 4);
	ft_sortthree(a, b);
	pa(a, b);
	pa(a, b);
	ra(a, b);
	ra(a, b);
}

void	ft_movenumber(t_stack **a, t_stack **b, int number)
{
	t_stack	*tmp;
	int		size;
	int		i;

	size = ft_stacksize(*a);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->number == number)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i > size / 2)
		while ((*a)->number != number)
			rra(a, b);
	else
		while ((*a)->number != number)
			ra(a, b);
	pb(a, b);
}
