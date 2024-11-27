/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_move_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:22 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 11:01:38 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile **a, int print)
{
	t_pile	*temp;
	t_pile	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	temp->len = 1;
	*a = (*a)->next;
	last = *a;
	while (last->next)
	{
		last->next->len++;
		last = last->next;
	}
	last->next = temp;
	temp->next = NULL;
	(*a)->len++;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_pile **b, int print)
{
	t_pile	*temp;
	t_pile	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	(*b)->len++;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_pile **a, t_pile **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
