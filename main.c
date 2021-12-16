/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/16 14:23:21 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <time.h>

int	main(int argc, char *argv[])
{
	t_instr	*instr;
	t_stack	*a;
	t_stack	*b;
	int		*index;

	if (argc != 2)
		ft_error();
	a = ft_create_stack(argv[1]);
	b = 0;
	instr = ft_init();
	index = ft_index(a);
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
