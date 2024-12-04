/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:23 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/04 16:38:09 by kbaridon         ###   ########.fr       */
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

	chunk_size = (abs(maximum(*a)) + abs(minimum(*a))) / 4;
	if ((*a)->len > 200)
		chunk_size = (abs(maximum(*a)) + abs(minimum(*a))) / 11;
	while (*a && !is_sorted(*a))
	{
		chunk_limit = minimum(*a) + chunk_size;
		while (has_elements_in_chunk(*a, chunk_limit))
			pb_in_order(a, b, chunk_limit, chunk_size);
	}
	put_to_a(a, b); //Pb : Prend parfois le chemin du min alors que ce n'est pas le plus opti
	//test avec : 74 94 83 54 2 12 88 1 76 90 3 59 66 67 42 27 14 46 5 93 40 6 28 35 44 80 34 39 84
	//57 20 8 49 75 100 51 68 19 52 17 48 56 22 31 97 7 87 77 11 89 29 30 32 86 33 16 95 81 38 91 58
	//82 65 92 23 85 4 18 25 79 45 53 9 63 36 15 64 61 21 41 24 72 69 73 78 37 55 26 43 70 99 13 10 71
	//50 47 98 60 62 96
	while (!is_sorted(*a))
		rra(a, 1);
}
