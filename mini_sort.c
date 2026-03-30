/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:31:28 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 11:12:21 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_env *env)
{
	int	a;
	int	b;
	int	c;

	a = env->node[env->head_a].nbr;
	b = env->node[env->node[env->head_a].next].nbr;
	c = env->node[env->node[env->node[env->head_a].next].next].nbr;
	if (a < b && b < c)
		return ;
	if (a > b && a > c)
		ra(env);
	else if (b > a && b > c)
		rra(env);
	a = env->node[env->head_a].nbr;
	b = env->node[env->node[env->head_a].next].nbr;
	if (a > b)
		sa(env);
}

int	find_min_pos(t_env *env)
{
	t_node_idx	cur;
	int			min;
	int			pos;
	int			i;
	int			first;

	cur = env->head_a;
	min = env->node[cur].nbr;
	pos = 0;
	i = 0;
	first = 1;
	while (cur != env->head_a || first)
	{
		first = 0;
		if (env->node[cur].nbr < min)
		{
			min = env->node[cur].nbr;
			pos = i;
		}
		cur = env->node[cur].next;
		++i;
	}
	return (pos);
}

void	rotate_to_top(t_env *env, int pos, int len)
{
	int	i;

	if (pos * 2 <= len)
	{
		i = -1;
		while (++i < pos)
			ra(env);
		return ;
	}
	i = -1;
	while (++i < len - pos)
		rra(env);
}

void	mini_sort(t_env *env, int len)
{
	if (len == 2)
	{
		if (env->node[env->head_a].nbr
			>env->node[env->node[env->head_a].next].nbr)
			sa(env);
		return ;
	}
	if (len == 3)
	{
		sort_three(env);
		return ;
	}
	while (len > 3)
	{
		rotate_to_top(env, find_min_pos(env), len);
		pb(env);
		--len;
	}
	sort_three(env);
	while (env->head_b)
		pa(env);
}
