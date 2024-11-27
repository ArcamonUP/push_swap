/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 16:44:03 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_or_rr(t_stack **stack, int chunk)
{
	t_stack	*temp;
	int		limit;
	int		op;

	if (!stack || !(*stack))
		return (0);
	limit = (*stack)->len / 2;
	temp = (*stack);
	op = 0;
	while (temp && temp->len > limit)
	{
		if (temp->content < chunk)
			op = (*stack)->len - temp->len;
		temp = temp->next;
	}
	if (!op)
		return (2);
	while (temp)
	{
		if (temp->content < chunk && temp->len < op)
			return (2);
		temp = temp->next;
	}
	return (1);
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk;

	if ((maximum(*a) - minimum(*a)) % 2 == 0)
		chunk = (maximum(*a) - minimum(*a)) / 2;
	else
		chunk = (maximum(*a) - minimum(*a)) / 3;
}
