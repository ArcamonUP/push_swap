/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/08 10:48:59 by kbaridon         ###   ########.fr       */
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

int	r_or_rr(t_stack **stack, int chunk)
{
	t_stack	*temp;
	t_stack	*pos_top;
	t_stack	*pos_bottom;

	if (!stack || !(*stack))
		return (0);
	temp = *stack;
	pos_top = NULL;
	while (temp)
	{
		if (temp->content <= chunk)
		{
			if (pos_top == NULL)
				pos_top = temp;
			pos_bottom = temp;
		}
		temp = temp->next;
	}
	if (((*stack)->len - pos_top->len) < pos_bottom->len)
		return (1);
	else if (((*stack)->len - pos_top->len) == pos_bottom->len)
		return ((pos_bottom->content < pos_top->content) + 1);
	return (2);
}

static void	pb_in_order(t_stack **a, t_stack **b, int limit, int chunk_size)
{
	if ((*a)->content <= limit)
	{
		pb(a, b);
		chunk_size++;
		if ((*b)->content <= (limit - (chunk_size / 2)))
		{
			if (has_elements_in_chunk(*a, limit) && r_or_rr(a, limit) == 1)
				rr(a, b);
			else
				rb(b, 1);
		}
	}
	else if (r_or_rr(a, limit) == 1)
		ra(a, 1);
	else
		rra(a, 1);
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	chunk_limit;
	int	nb_chunk;

	nb_chunk = 3;
	if ((*a)->len > 200)
		nb_chunk = 9;
	chunk_size = ((abs(maximum(*a)) + abs(minimum(*a))) / nb_chunk) + 1;
	while (*a && !is_sorted(*a))
	{
		chunk_limit = minimum(*a) + chunk_size;
		while (has_elements_in_chunk(*a, chunk_limit))
			pb_in_order(a, b, chunk_limit, chunk_size);
	}
	put_to_a(a, b);
	while (!is_sorted(*a))
		rra(a, 1);
}
