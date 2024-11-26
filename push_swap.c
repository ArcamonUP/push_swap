/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 15:26:27 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*temp;

	(void)ac;
	a = init(av[1]);
	if (!a)
		return (0);
	sort_dispatch(&a);
	temp = a;
	while (temp->next)
	{
		printf("Content : %i | taille : %zu\n", temp->content, temp->len);
		temp = temp->next;
	}
	printf("Content : %i | taille : %zu\n", temp->content, temp->len);
	free_pile(a);
}
