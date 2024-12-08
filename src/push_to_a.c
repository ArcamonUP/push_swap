/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:11:53 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/08 13:41:39 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_to_top(t_stack **stack)
{
	int		value;
	t_stack	*temp;

	value = maximum(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->content == value)
		{
			if (temp->len == (*stack)->len)
				break ;
			if (((*stack)->len - temp->len) < temp->len)
				return (1);
			else
				return (2);
		}
		temp = temp->next;
	}
	return (0);
}

static int	last_elem(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}

static void	organize(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next)
	{
		while (last_elem(a) < maximum(*a) && last_elem(a) > maximum(*b))
		{
			if (cost_to_top(b) == 2)
				rrr(a, b, 1);
			else
				rra(a, 1);
		}
	}
}

static void	put_to_top(t_stack **a, t_stack **b)
{
	int	i;

	i = cost_to_top(b);
	if (!(*a) || !(*a)->next)
	{
		while ((*b)->content != maximum(*b))
		{
			if (i == 1)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
	else
	{
		while ((*b)->content != maximum(*b) && \
		(last_elem(a) < maximum(*a) && (*b)->content < last_elem(a)))
		{
			if (i == 1)
				rb(b, 1);
			else
				rrb(b, 1);
		}
	}
}

void	put_to_a(t_stack **a, t_stack **b)
{
	while ((*b))
	{
		organize(a, b);
		put_to_top(a, b);
		pa(a, b, 1);
		if (((*b) && maximum(*b) > (*a)->content) && cost_to_top(b) == 1)
			rr(a, b, 1);
		else if ((*b) && maximum(*b) > (*a)->content)
			ra(a, 1);
	}
}
