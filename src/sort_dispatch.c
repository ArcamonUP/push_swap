/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:16 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->len == 2)
	{
		sa(*a, 1);
		return ;
	}
	if ((*a)->len == 3)
		return (sort_three_value(a));
	if ((*a)->len == 4)
		return (sort_four_value(a, b));
	if ((*a)->len == 5)
		return (sort_five_value(a, b));
	return (sort(a, b));
}
