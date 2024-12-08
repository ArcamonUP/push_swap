/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:25:22 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/08 14:05:29 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_move(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(move, "sa\n", 3))
		sa(*a, 0);
	else if (!ft_strncmp(move, "sb\n", 3))
		sb(*b, 0);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(*a, *b, 0);
	else if (!ft_strncmp(move, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(move, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(move, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(move, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(a, b, 0);
	else
		free(move);
}

static void	check_sort(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		do_move(move, a, b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (is_sorted(*a) && !(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	if (ac == 2)
		a = pre_init(&av[1]);
	else
	{
		av++;
		a = pre_init(av);
	}
	b = NULL;
	if (!a)
		return (0);
	check_sort(&a, &b);
	free_stack(a);
	free_stack(b);
}
