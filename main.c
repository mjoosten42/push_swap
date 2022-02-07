/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:12 by mjoosten          #+#    #+#             */
/*   Updated: 2022/02/07 11:12:14 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	a = ft_create_stack(argv);
	b = 0;
	if (ft_stack_issorted(a, b))
		exit(EXIT_SUCCESS);
	if (argc == 3)
		sa(&a, &b);
	if (argc == 4)
		ft_sortthree(&a, &b);
	if (argc == 5)
		ft_sortfour(&a, &b);
	if (argc == 6)
		ft_sortfive(&a, &b);
	if (argc >= 7)
		ft_sort(&a, &b);
	ft_freestack(a);
	exit(EXIT_SUCCESS);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
