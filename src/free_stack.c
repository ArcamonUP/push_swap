/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:42 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:16 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack->next)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(stack);
}
