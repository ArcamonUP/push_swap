/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:13:52 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/03 17:16:23 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost(t_stack **stack, int value)
{
	t_stack	*temp;
	int		result;

	if (!*stack)
		return (0);
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

static int	get_last(t_stack **stack, int chunk)
{
	t_stack	*temp;
	int		last;

	last = -1;
	temp = *stack;
	while (temp)
	{
		if (temp->content <= chunk)
			last = temp->content;
		temp = temp->next;
	}
	return (last);
}

static int	get_second(t_stack **stack, int chunk)
{
	t_stack	*temp;
	int		second;
	int		i;

	i = 0;
	second = -1;
	temp = *stack;
	while (temp)
	{
		if (temp->content <= chunk)
			i++;
		if (i == 2)
			second = temp->content;
		temp = temp->next;
	}
	return (second);
}

static int	calculate_cost(t_stack *stack, int chunk, int count, int is_reverse)
{
	t_stack	*temp_copy;
	int		cost;
	int		cost_last;
	int		cost_second;
	int		i;

	i = 0;
	temp_copy = copy_stack(stack);
	if (!temp_copy)
		return (-1);
	while (i < count)
	{
		if (is_reverse)
			rra(&temp_copy, 0);
		else
			ra(&temp_copy, 0);
		i++;
	}
	cost_last = get_cost(&temp_copy, get_last(&temp_copy, chunk));
	cost_second = get_cost(&temp_copy, get_second(&temp_copy, chunk));
	if (cost_last < cost_second)
		cost = cost_last + count - (is_reverse ? 0 : 1);
	else
		cost = cost_second + count - (is_reverse ? 0 : 1);
	free_pile(temp_copy);
	return (cost);
}

static int	get_two_cost(t_stack **stack, int chunk, int nbr, int nbrr)
{
	int	r;
	int	rr;

	r = calculate_cost(*stack, chunk, nbr, 0);
	if (r == -1)
		return (0);
	rr = calculate_cost(*stack, chunk, nbrr, 1);
	if (rr == -1)
		return (0);
	if (r <= rr)
		return (1);
	return (2);
}

static int	r_or_rr(t_stack **stack, int chunk)
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
	if (pos_bottom->content != pos_top->content)
		return (get_two_cost(stack, chunk, \
		(*stack)->len - pos_top->len, pos_bottom->len));
	if (((*stack)->len - pos_top->len) <= pos_bottom->len)
		return (1);
	return (2);
}

t_stack *copy_stack(t_stack *stack)
{
	t_stack *new_stack = NULL;
	t_stack *current = stack;
	t_stack *new_node;
	t_stack *last_node = NULL;

	while (current)
	{
		new_node = pilenew(current->content);
		if (!new_node)
		{
			free_pile(new_stack);
			return (NULL);
		}
		if (last_node)
			last_node->next = new_node;
		else
			new_stack = new_node;
		last_node = new_node;
		current = current->next;
	}
	return (new_stack);
}
