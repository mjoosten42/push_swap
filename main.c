/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 17:07:27 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*sorted;
	int		*index;

	if (argc != 2)
		return (1);
	a = ft_create_stack(argv[1]);
	b = 0;
	sorted = ft_stacksort(a);
	index = calloc(sizeof(*index), ft_stackmax(sorted));
	ft_index(a, index);
	free(index);
	exit(EXIT_SUCCESS);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_index(t_stack *sorted, int *index)
{
	int	i;

	i = 0;
	while (sorted)
	{
		index[sorted->number] = i;
		sorted = sorted->next;
		i++;
	}
}

void	printstack(t_stack *stack)
{
	printf("Stack: ");
	while (stack)
	{
		printf("%d ", stack->number);
		stack = stack->next;
	}
	printf("\n");
}
