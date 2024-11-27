/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:17:18 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 17:21:24 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	is_valid_num(char *num)
{
	int		len;
	int		i;
	char	*max;

	len = ft_strlen(num);
	if (len > 11 || (len == 11 && num[0] != '-'))
		return (0);
	if (num[0] == '-')
		max = "-2147483648";
	else
		max = "2147483647";
	i = 0;
	if (len == 11 || (len == 10 && num[0] != '-'))
	{
		while (max[i])
		{
			if (num[i] < max[i])
				return (1);
			else if (num[i] > max[i])
				return (0);
			i++;
		}
	}
	return (1);
}

static int	valid_args(char **args)
{
	int	i;
	int	y;
	int	t;

	i = 0;
	while (args[i])
	{
		y = i + 1;
		t = 0;
		if (args[i][0] == '-' && args[i][1])
			t++;
		while (args[i][t] && args[i][t] >= '0' && args[i][t] <= '9' && t < 11)
			t++;
		if (args[i][t] || !is_valid_num(args[i]))
			return (0);
		while (args[y])
		{
			if (ft_strcmp(args[i], args[y]) == 0)
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

static void	add_top(t_pile **a, t_pile *new)
{
	t_pile	*temp;

	temp = *a;
	if (!new || !a)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	while (temp->next)
	{
		temp->next->len++;
		temp = temp->next;
	}
	temp->next = new;
}


t_pile	*init(char *list)
{
	t_pile	*a;
	t_pile	*temp;
	char	**tab_args;

	tab_args = ft_split(list, ' ');
	if (!tab_args || !valid_args(tab_args))
	{
		write(2, "Error\n", 6);
		return (free_args(tab_args), NULL);
	}
	a = pilenew(ft_atoi(tab_args[0]));
	if (!a)
		return (free_args(tab_args), free(a), NULL);
	while (tab_args[a->len])
	{
		temp = pilenew(ft_atoi(tab_args[a->len]));
		if (!temp)
			return (free_pile(a), free_args(tab_args), NULL);
		add_top(&a, temp);
		a->len++;
	}
	return (free_args(tab_args), a);
}
