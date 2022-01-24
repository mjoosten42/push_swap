/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:25:03 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 14:32:55 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	*str;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		ft_error();
	a = ft_create_stack(argv);
	b = 0;
	str = ft_get_next_line(0);
	while (str)
	{
		write(1, str, ft_strlen(str));
		free(str);
		str = ft_get_next_line(0);
	}
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
