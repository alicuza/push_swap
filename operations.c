/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:00:12 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/29 12:54:09 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	swap(env->node, &env->head_a);
}

void	sb(t_env *env)
{
	swap(env->node, &env->head_b);
}

void	ss(t_env *env)
{
	swap(env->node, &env->head_a);
	swap(env->node, &env->head_b);
}

void	pa(t_env *env)
{
	push(env->node, &env->head_a, &env->head_b);
}

void	pb(t_env *env)
{
	push(env->node, &env->head_b, &env->head_a);
}

void ra(t_env *env)
{
	rotate(env->node, &env->head_a);
}

void rb(t_env *env)
{
	rotate(env->node, &env->head_b);
}

void rr(t_env *env)
{
	rotate(env->node, &env->head_a);
	rotate(env->node, &env->head_b);
}

void rra(t_env *env)
{
	reverse_rotate(env->node, &env->head_a);
}

void rrb(t_env *env)
{
	reverse_rotate(env->node, &env->head_b);
}

void rrr(t_env *env)
{
	reverse_rotate(env->node, &env->head_a);
	reverse_rotate(env->node, &env->head_b);
}
