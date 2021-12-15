/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:14 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 10:15:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(char *str)
{
	t_stack	*stack;
	t_stack	*new;
	char	**strs;
	int		i;

	i = 0;
	stack = 0;
	strs = ft_split(str, ' ');
	if (!strs)
		ft_error();
	while (strs[i])
	{
		new = malloc(sizeof(*new));
		if (!new)
			ft_error();
		new->number = ft_atoi(strs[i]);
		new->next = stack;
		stack = new;
		i++;
	}
	ft_free_array((void **)strs);
	return (ft_stackreverse(stack));
}

t_stack	*ft_stackreverse(t_stack *stack)
{
	t_stack	*next;
	t_stack	*prev;

	prev = 0;
	while (stack)
	{
		next = stack->next;
		stack->next = prev;
		prev = stack;
		stack = next;
	}
	return (prev);
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
