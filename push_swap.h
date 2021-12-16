/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:25:02 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/16 15:24:34 by mjoosten         ###   ########.fr       */
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
}					t_stack;

typedef struct s_instr
{
	char	**strs;
	int		*index;
	void	(**fct)(t_stack **a, t_stack **b);
	void	(**rev)(t_stack **a, t_stack **b);
}			t_instr;

int		printstack(t_stack *stack);

void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_instr	*ft_init(t_stack *a);
void	*ft_initfct(void);
void	*ft_initrev(void);
char	**ft_initstrs(void);
int		*ft_index(t_stack *a);

t_stack	*ft_create_stack(char *argv);
t_stack	*ft_stackreverse(t_stack *stack);
int		ft_stackfirst(t_stack *stack);
int		ft_stacklast(t_stack *stack);
t_stack	*ft_stacksort(t_stack *stack);
void	ft_stackinsert(t_stack **stack, t_stack *new);

int		ft_checknumber(t_stack *stack, char *str);
int		ft_error(void);

void	ft_sort(t_stack **a, t_stack **b);

#endif