/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:25:02 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/17 14:52:42 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

# include <stdio.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

void		printstack(t_stack *stack);

void		sa(t_stack **a, t_stack **b);
void		sb(t_stack **a, t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a, t_stack **b);
void		rb(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a, t_stack **b);
void		rrb(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

int			ft_stack_issorted(t_stack *a);
t_stack		*ft_create_stack(char **argv);
t_stack		*ft_stackclean(t_stack *orig);
int			ft_amount_lower(t_stack *stack, int number);
void		ft_freestack(t_stack *stack);
int			ft_stacksize(t_stack *stack);

void		ft_sort(t_stack **a, t_stack **b);
void		ft_sortthree(t_stack **a, t_stack **b);
void		ft_sortfive(t_stack **a, t_stack **b);

int			ft_remainder_issorted(t_stack *a, int bits, int remainder);
int			ft_long_atoi(const char *str);
int			ft_isspace(char c);

int			ft_checknumber(t_stack *stack, char *str);
int			ft_error(void);

#endif