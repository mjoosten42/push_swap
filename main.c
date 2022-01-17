/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/17 13:55:33 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		ft_error();
	a = ft_create_stack(argv);
	if (ft_stack_issorted(a))
		exit(EXIT_SUCCESS);
	b = 0;
	ft_sort(&a, &b);
	exit(EXIT_SUCCESS);
}	

int	printstack(t_stack *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("%d ", stack->number);
		stack = stack->next;
	}
	printf("\n");
	return (0);
}

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

int	ft_stack_issorted(t_stack *a)
{
	int	number;

	number = a->number;
	a = a->next;
	while (a)
	{
		if (a->number < number)
			return (0);
		number = a->number;
		a = a->next;
	}
	return (1);
}
