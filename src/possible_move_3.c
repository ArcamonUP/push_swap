/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_move_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:33:36 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:16 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack	*prev;
	int		len;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	len = 1;
	prev = NULL;
	while (temp->next)
	{
		temp->len--;
		prev = temp;
		temp = temp->next;
		len++;
	}
	prev->next = NULL;
	temp->next = *a;
	*a = temp;
	(*a)->len = len;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*prev;
	int		len;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	len = 1;
	prev = NULL;
	while (temp->next)
	{
		temp->len--;
		prev = temp;
		temp = temp->next;
		len++;
	}
	prev->next = NULL;
	temp->next = *b;
	*b = temp;
	(*b)->len = len;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
