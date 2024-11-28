/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/28 15:39:25 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_elements_in_chunk(t_stack *stack, int chunk_limit)
{
	while (stack)
	{
		if (stack->content <= chunk_limit)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	r_or_rr(t_stack **stack, int chunk)
{
	t_stack	*temp;
	int		pos_top;
	int		pos_bottom;

	if (!stack || !(*stack))
		return (0);
	temp = *stack;
	pos_top = -1;
	pos_bottom = -1;
	while (temp)
	{
		if (temp->content <= chunk)
		{
			if (pos_top == -1)
				pos_top = (*stack)->len - temp->len;
			pos_bottom = temp->len;
		}
		temp = temp->next;
	}
	if (pos_top == -1)
		return (0);
	if (pos_top <= pos_bottom)
		return (1);
	return (2);
}

static void	move_max_to_top(t_stack **stack)
{
	int		max;
	int		i;
	t_stack	*temp;

	max = maximum(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->content == max)
		{
			if (((*stack)->len - temp->len) <= temp->len)
				i = 1;
			else
				i = 2;
			break ;
		}
		temp = temp->next;
	}
	while ((*stack)->content != max)
	{
		if (i == 1)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	chunk_limit;

	chunk_size = (*a)->len / 5;
	if ((*a)->len > 100)
		chunk_size = (*a)->len / 10;
	while (*a && !is_sorted(*a))
	{
		chunk_limit = minimum(*a) + chunk_size;
		while (has_elements_in_chunk(*a, chunk_limit) && !is_sorted(*a))
		{
			if ((*a)->content <= chunk_limit)
				pb(a, b);
			else if (r_or_rr(a, chunk_limit) == 1)
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
