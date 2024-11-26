/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:36:01 by kbaridon          #+#    #+#             */
/*   Updated: 2024/11/26 14:58:37 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				content;
	struct s_pile	*next;
	size_t			len;
}	t_pile;

int		minimum(t_pile *pile);
int		maximum(t_pile *pile);
int		is_sorted(t_pile *a);
void	sa(t_pile *a, int print);
void	sb(t_pile *b, int print);
void	ss(t_pile *a, t_pile *b);
void	pb(t_pile **a, t_pile **b);
void	pa(t_pile **a, t_pile **b);
void	ra(t_pile **a, int print);
void	rb(t_pile **b, int print);
void	rr(t_pile **a, t_pile **b);
void	rra(t_pile **a, int print);
void	rrb(t_pile **b, int print);
void	rrr(t_pile **a, t_pile **b);
void	sort_dispatch(t_pile **a);
t_pile	*init(char *list);
t_pile	*pilenew(int content);
int		ft_strcmp(char *s1, char *s2);
void	free_pile(t_pile *pile);
void	sort_three_value(t_pile **a);
void	sort_four_value(t_pile **a, t_pile **b);
void	sort_five_value(t_pile **a, t_pile **b);

char	**ft_split(const char *str, char c);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif