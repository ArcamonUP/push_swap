/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:53:45 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/13 13:38:43 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_tab(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static void	*free_tab(int x, char **tab)
{
	if (x == 0)
		free(tab);
	else
	{
		while (x >= 0)
		{
			free(tab[x]);
			x--;
		}
		free(tab);
	}
	return (NULL);
}

void	init_tab(int tab[3])
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		tab[3];

	init_tab(tab);
	result = malloc(sizeof(char *) * (ft_count_tab(str, c) + 1));
	if (!result)
		return (free_tab(tab[2], result));
	while (str[tab[0]])
	{
		if (str[tab[0]] == c)
			tab[0]++;
		else
		{
			tab[1] = tab[0];
			while (str[tab[0]] && str[tab[0]] != c)
				tab[0]++;
			result[tab[2]] = malloc(sizeof(char) * (tab[0] - tab[1] + 1));
			if (!result[tab[2]])
				return (free_tab(tab[2], result));
			ft_strlcpy(result[tab[2]], str + tab[1], tab[0] - tab[1] + 1);
			tab[2]++;
		}
	}
	result[tab[2]] = NULL;
	return (result);
}
