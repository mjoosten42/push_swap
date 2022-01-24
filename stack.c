/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:14 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 14:35:05 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 1;
	stack = 0;
	while (argv[i])
	{
		new = malloc(sizeof(*new));
		if (!new)
			ft_error();
		new->number = ft_long_atoi(argv[i]);
		ft_checknumber(stack, argv[i]);
		new->next = stack;
		stack = new;
		i++;
	}
	return (ft_stackclean(stack));
}

t_stack	*ft_stackclean(t_stack *orig)
{
	t_stack	*stack;
	t_stack	*new;
	t_stack	*tmp;

	stack = 0;
	tmp = orig;
	while (tmp)
	{
		new = malloc(sizeof(*new));
		if (!new)
			ft_error();
		new->number = ft_amount_lower(orig, tmp->number);
		new->next = stack;
		stack = new;
		tmp = tmp->next;
	}
	ft_freestack(orig);
	return (stack);
}

void	ft_freestack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
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

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
