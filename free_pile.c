/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:42 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 14:58:02 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_pile *pile)
{
	t_pile	*temp;

	while (pile->next)
	{
		temp = pile->next;
		free(pile);
		pile = temp;
	}
	free(pile);
}
