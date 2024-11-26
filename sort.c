/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 16:14:54 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_pile **a, t_pile **b)
{
	(void)a;
	(void)b;
}

void	sort_dispatch(t_pile **a)
{
	t_pile	*b;

	if (is_sorted(*a))
		return ;
	if ((*a)->len == 2)
	{
		sa(*a, 1);
		return ;
	}
	if ((*a)->len == 3)
		return (sort_three_value(a));
	b = NULL;
	if ((*a)->len == 4)
		return (sort_four_value(a, &b));
	if ((*a)->len == 5)
		return (sort_five_value(a, &b));
	return (sort(a, &b));
}
