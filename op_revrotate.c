/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:27:24 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 02:38:54 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_node *node, t_stack_idx *head)
{
	if (!node[*head].prev || node[*head].next == *head)
		return (0);
	*head = node[*head].prev;
	return (1);
}

void rra(t_env *env)
{
	if (rev_rotate(env->node, &env->head_a))
		ft_printf("rra\n");
}

void rrb(t_env *env)
{
	if (rev_rotate(env->node, &env->head_b))
		ft_printf("rrb\n");
}

void rrr(t_env *env)
{
	if (rev_rotate(env->node, &env->head_a)
			&& rev_rotate(env->node, &env->head_b))
		ft_printf("rrr\n");
}
