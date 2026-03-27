/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:00:12 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/27 12:51:36 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_env *env)
{
	swap(env->node, &env->head_a);
}

void sb(t_env *env)
{
	swap(env->node, &env->head_b);
}

void ss(t_env *env)
{
	swap(env->node, &env->head_a);
	swap(env->node, &env->head_b);
}

