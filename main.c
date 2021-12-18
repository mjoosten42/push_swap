/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/18 15:35:14 by mjoosten         ###   ########.fr       */
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
	b = 0;
	ft_sort(&a, &b);
	printf("---Final---\n");
	printstack(a);
	printstack(b);
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

	size = 4;
	while (size--)
	{
		if ((*a)->number % 2)
			ra(a, b);
		else
			pb(a, b);
	}
	pa(a, b);
	pa(a, b);
	printstack(*a);
	size = 4;
	while (size--)
	{
		if ((*a)->number >> 1 % 2)
			ra(a, b);
		else
			pb(a, b);
	}
	pa(a, b);
	pa(a, b);
}

int	ft_issorted(t_stack *a)
{
	if (!a->next)
		return (1);
	while (a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_pow(int nb, int pow)
{
	int	sum;

	if (!pow)
		return (1);
	sum = nb;
	pow--;
	while (pow--)
		sum *= nb;
	return (sum);
}
