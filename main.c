/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/20 10:48:55 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		ft_error();
	a = ft_create_stack(argv);
	b = 0;
	if (ft_stack_issorted(a, b))
		exit(EXIT_SUCCESS);
	if (argc == 3)
		sa(&a, &b);
	if (argc == 4)
		ft_sortthree(&a, &b);
	if (argc == 5)
		ft_sortfour(&a, &b);
	if (argc == 6)
		ft_sortfive(&a, &b);
	if (argc >= 7)
		ft_sort(&a, &b);
	exit(EXIT_SUCCESS);
}

int	ft_stack_issorted(t_stack *a, t_stack *b)
{
	int	number;

	if (!a || b)
		return (0);
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

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
