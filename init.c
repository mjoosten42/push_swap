/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:41:05 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/16 15:30:36 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*ft_init(t_stack *a)
{
	t_instr	*instr;

	instr = malloc(sizeof(*instr));
	if (!instr)
		ft_error();
	instr->fct = ft_initfct();
	instr->rev = ft_initrev();
	instr->strs = ft_initstrs();
	instr->index = ft_index(a);
	return (instr);
}

void	*ft_initfct(void)
{
	void	(**f)(t_stack **a, t_stack **b);

	f = malloc(sizeof(*f) * 12);
	if (!f)
		ft_error();
	f[0] = sa;
	f[1] = sb;
	f[2] = ss;
	f[3] = pa;
	f[4] = pb;
	f[5] = ra;
	f[6] = rb;
	f[7] = rr;
	f[8] = rra;
	f[9] = rrb;
	f[10] = rrr;
	f[11] = 0;
	return (f);
}

void	*ft_initrev(void)
{
	void	(**frev)(t_stack **a, t_stack **b);

	frev = malloc(sizeof(*frev) * 12);
	if (!frev)
		ft_error();
	frev[0] = sa;
	frev[1] = sb;
	frev[2] = ss;
	frev[3] = pb;
	frev[4] = pa;
	frev[5] = rra;
	frev[6] = rrb;
	frev[7] = rrr;
	frev[8] = ra;
	frev[9] = rb;
	frev[10] = rr;
	frev[11] = 0;
	return (frev);
}

char	**ft_initstrs(void)
{
	char	**strs;
	int		i;

	strs = malloc(sizeof(*strs) * 12);
	if (!strs)
		ft_error();
	strs[0] = ft_strdup("sa");
	strs[1] = ft_strdup("sb");
	strs[2] = ft_strdup("ss");
	strs[3] = ft_strdup("pa");
	strs[4] = ft_strdup("pb");
	strs[5] = ft_strdup("ra");
	strs[6] = ft_strdup("rb");
	strs[7] = ft_strdup("rr");
	strs[8] = ft_strdup("rra");
	strs[9] = ft_strdup("rrb");
	strs[10] = ft_strdup("rrr");
	strs[11] = 0;
	i = 0;
	while (strs[i])
		i++;
	if (i != 11)
		ft_error();
	return (strs);
}

int	*ft_index(t_stack *a)
{
	t_stack	*sorted;
	int		*index;
	int		most;
	int		least;
	int		i;

	sorted = ft_stacksort(a);
	most = ft_stacklast(sorted);
	if (most < 0)
		most = 0;
	least = ft_stackfirst(sorted);
	if (least > 0)
		least = 0;
	index = calloc(sizeof(*index), most - least);
	i = 0;
	while (sorted)
	{
		index[sorted->number] = i;
		sorted = sorted->next;
		i++;
	}
	free(sorted);
	return (index - least);
}
