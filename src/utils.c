/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:32 by kbaridon          #+#    #+#             */
/*   Updated: 2024/12/02 13:36:09 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = temp->content;
	temp = stack;
	while (temp->next)
	{
		if (temp->content < i)
			i = temp->content;
		temp = temp->next;
	}
	if (temp->content < i)
		i = temp->content;
	return (i);
}

int	maximum(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = temp->content;
	temp = stack;
	while (temp->next)
	{
		if (temp->content > i)
			i = temp->content;
		temp = temp->next;
	}
	if (temp->content > i)
		i = temp->content;
	return (i);
}

int	is_sorted(t_stack *a)
{
	t_stack	*temp;
	int		i;

	temp = a;
	i = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->content < i)
			return (0);
		i = temp->content;
	}
	return (1);
}

t_stack	*pilenew(int content)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(*result));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	result->len = 1;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	if (s2[i])
		return (-s2[i]);
	return (0);
}
