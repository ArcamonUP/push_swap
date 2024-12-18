/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/08 13:54:14 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	if (ac == 2)
		a = pre_init(&av[1]);
	else
	{
		av++;
		a = pre_init(av);
	}
	b = NULL;
	if (!a)
		return (0);
	sort_dispatch(&a, &b);
	free_stack(a);
	free_stack(b);
}
