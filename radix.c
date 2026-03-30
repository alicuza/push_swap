/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:35:29 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 01:35:52 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compress_values(t_env *env)
{
	t_node_idx	cur;
	t_node_idx	cmp;
	int			first_out;
	int			first_in;

	cur = env->head_a;
	first_out = 1;
	while (cur != env->head_a || first_out)
	{
		first_out = 0;
		env->node[cur].rank = 0;
		cmp = env->head_a;
		first_in = 1;
		while (cmp != env->head_a || first_in)
		{
			first_in = 0;
			if (env->node[cmp].nbr < env->node[cur].nbr)
				++env->node[cur].rank;
			cmp = env->node[cmp].next;
		}
		cur = env->node[cur].next;
	}
}

static int	max_bits(t_env *env)
{
	t_node_idx	cur;
	int			max;
	int			bits;
	int			first;

	cur = env->head_a;
	max = env->node[cur].rank;
	bits = 0;
	first = 1;
	while (cur != env->head_a || first)
	{
		first = 0;
		if (env->node[cur].rank > max)
			max = env->node[cur].rank;
		cur = env->node[cur].next;
	}
	while ((max >> bits) != 0)
		++bits;
	return (bits);
}

void	radix_sort(t_env *env, int len)
{
	int		i;
	int		bit;
	int		bit_cnt;

	bit_cnt = max_bits(env);
	bit = 0;
	while (bit < bit_cnt)
	{
		i = -1;
		while (++i < len)
		{
			if (!((env->node[env->head_a].rank >> bit) & 1))
				pb(env);
			else
				ra(env);
		}
		while (env->head_b)
			pa(env);
		++bit;
	}
}
