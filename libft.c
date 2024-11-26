/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:09:51 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/25 14:26:47 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = (size_t)ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	result;

	i = 0;
	nb = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb = -nb;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * nb);
}

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

static void	init_tab(int tab[3])
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
