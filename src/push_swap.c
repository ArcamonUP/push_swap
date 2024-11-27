/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:32:46 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/27 12:34:48 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	t_pile	*temp;

	(void)ac;
	a = init(av[1]);
	b = NULL;
	if (!a)
		return (0);
	sort_dispatch(&a, &b);
	temp = a;
	while (temp->next)
	{
		ft_printf("Content : %i | taille : %i\n", temp->content, temp->len);
		temp = temp->next;
	}
	ft_printf("Content : %i | taille : %i\n", temp->content, temp->len);
	free_pile(a);
	free_pile(b);
}
