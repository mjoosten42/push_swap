/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:14 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/17 13:55:10 by mjoosten         ###   ########.fr       */
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
