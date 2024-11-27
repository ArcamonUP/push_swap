/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-kb <linux-kb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 21:17:49 by linux-kb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	move_max_to_top(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		pos_top;
	int		pos_bottom;

	temp = *stack;
	max = maximum(*stack);
	pos_top = -1;
	pos_bottom = -1;
	while (temp)
	{
		if (temp->content == max)
		{
			if (pos_top == -1)
				pos_top = (*stack)->len - temp->len;
			pos_bottom = (*stack)->len - temp->len;;
		}
		temp = temp->next;
	}
	if (pos_top <= ((*stack)->len - pos_bottom - 1))
		while ((*stack)->content != max)
			rb(stack, 1);
	else
		while ((*stack)->content != max)
			rrb(stack, 1);
}

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
			pos_bottom = (*stack)->len - temp->len;
		}
		temp = temp->next;
	}
	if (pos_top == -1)
		return (0);
	if (pos_top <= ((*stack)->len - pos_bottom - 1))
		return (1);
	return (2);
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	chunk_limit;
	int	current_min;

	chunk_size = (*a)->len / 5;
	current_min = minimum(*a);
	while (*a)
	{
		chunk_limit = current_min + chunk_size;
		while (has_elements_in_chunk(*a, chunk_limit))
		{
			if ((*a)->content <= chunk_limit)
				pb(a, b);
			else if (r_or_rr(a, chunk_limit) == 1)
				ra(a, 1);
			else
				rra(a, 1);
		}
		current_min = chunk_limit;
	}
	while (*b)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
