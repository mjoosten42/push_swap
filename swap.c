/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:27 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 10:14:45 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	first = *b;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
