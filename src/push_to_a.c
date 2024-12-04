/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:11:53 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/04 16:36:07 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost(t_stack **stack, int value)
{
	t_stack	*temp;
	int		result;

	temp = *stack;
	result = 0;
	while (temp)
	{
		if (temp->content == value)
		{
			if (((*stack)->len - temp->len) < temp->len)
				result = (*stack)->len - temp->len;
			else
				result = temp->len;
			break ;
		}
		temp = temp->next;
	}
	return (result);
}

static int	move_to_top(t_stack **stack)
{
	int		value;
	t_stack	*temp;

	value = maximum(*stack);
	if (get_cost(stack, minimum(*stack) + 2 < get_cost(stack, value)))
		value = minimum(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->content == value)
		{
			if (temp->len == (*stack)->len)
				break ;
			if (((*stack)->len - temp->len) <= temp->len)
				return (1);
			else
				return (2);
		}
		temp = temp->next;
	}
	return (0);
}

void	put_to_a(t_stack **a, t_stack **b)
{
	int	i;

	while ((*b))
	{
		i = move_to_top(b);
		while ((*b)->content != maximum(*b) && (*b)->content != minimum(*b))
		{
			if (i == 1)
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(a, b);
		if ((*b) && (*a)->content < maximum(*b))
		{
			if (move_to_top(b) == 1)
				rr(a, b);
			else
				ra(a, 1);
		}
	}
}
