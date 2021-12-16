/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:14 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/16 14:19:23 by mjoosten         ###   ########.fr       */
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
		ft_checknumber(stack, strs[i]);
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

int	ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack->number);
}

t_stack	*ft_stacksort(t_stack *stack)
{
	t_stack	*sorted;
	t_stack	*new;

	sorted = 0;
	while (stack)
	{
		new = malloc(sizeof(*new));
		if (!new)
			ft_error();
		new->number = stack->number;
		new->next = 0;
		ft_stackinsert(&sorted, new);
		stack = stack->next;
	}
	return (sorted);
}

void	ft_stackinsert(t_stack **stack, t_stack *new)
{
	t_stack	*prev;
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	prev = 0;
	tmp = *stack;
	while (new->number > tmp->number)
	{
		prev = tmp;
		tmp = tmp->next;
		if (!tmp)
			break ;
	}
	new->next = tmp;
	if (prev)
		prev->next = new;
	else
		*stack = new;
}
