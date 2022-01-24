/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:20:08 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 14:53:38 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = tmp->next;
	ptr = *a;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->next = 0;
	(void)b;
}

void	rb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = tmp->next;
	ptr = *b;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->next = 0;
	(void)a;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
}
