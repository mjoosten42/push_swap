/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:27 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/18 12:43:34 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
	(void)b;
}

void	sb(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
	(void)a;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, b);
	sb(a, b);
	write(1, "ss\n", 3);
}
