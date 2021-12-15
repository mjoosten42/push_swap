/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:20:08 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 10:34:21 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	ptr = *a;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	else
		*a = tmp;
	tmp->next = 0;
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	ptr = *b;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	else
		*b = tmp;
	tmp->next = 0;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
