/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:25:03 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 17:47:38 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(char *str, t_stack **a, t_stack **b);

int	main(int argc, char *argv[])
{
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = ft_create_stack(argv);
	b = 0;
	str = ft_get_next_line(0);
	while (str)
	{
		ft_parse(str, &a, &b);
		free(str);
		str = ft_get_next_line(0);
	}
	if (ft_stack_issorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freestack(a);
	ft_freestack(b);
	exit(EXIT_SUCCESS);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_parse(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(str, "sa\n", 4))
		sa(a, b);
	else if (!ft_strncmp(str, "sb\n", 4))
		sb(a, b);
	else if (!ft_strncmp(str, "ss\n", 4))
		ss(a, b);
	else if (!ft_strncmp(str, "pa\n", 4))
		pa(a, b);
	else if (!ft_strncmp(str, "pb\n", 4))
		pb(a, b);
	else if (!ft_strncmp(str, "ra\n", 4))
		ra(a, b);
	else if (!ft_strncmp(str, "rb\n", 4))
		rb(a, b);
	else if (!ft_strncmp(str, "rr\n", 4))
		rr(a, b);
	else if (!ft_strncmp(str, "rra\n", 5))
		rra(a, b);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrb(a, b);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rrr(a, b);
	else
		ft_error();
}
