/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:35:41 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 14:53:33 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	prev = 0;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = 0;
	tmp->next = *a;
	*a = tmp;
	(void)b;
}

void	rrb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	prev = 0;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = 0;
	tmp->next = *b;
	*b = tmp;
	(void)a;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
}
