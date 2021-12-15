/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:25:02 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/15 16:55:02 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

void	printstack(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*ft_create_stack(char *argv);
t_stack	*ft_stackreverse(t_stack *stack);
int		ft_stackmax(t_stack *stack);
t_stack	*ft_stacksort(t_stack *stack);
void	ft_stackinsert(t_stack **stack, t_stack *new);
void	ft_index(t_stack *sorted, int *index);

int		ft_error(void);

#endif