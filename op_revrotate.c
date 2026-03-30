/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:27:24 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 14:09:32 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_node *node, t_stack_idx *head)
{
	if (node[*head].next == *head)
		return (0);
	*head = node[*head].prev;
	return (1);
}

void	rra(t_env *env)
{
	if (rev_rotate(env->node, &env->head_a))
		ft_printf("rra\n");
}

void	rrb(t_env *env)
{
	if (rev_rotate(env->node, &env->head_b))
		ft_printf("rrb\n");
}

void	rrr(t_env *env)
{
	if (stack_len(env->node, env->head_a) < 2
		|| stack_len(env->node, env->head_b) < 2)
		return ;
	rev_rotate(env->node, &env->head_a);
	rev_rotate(env->node, &env->head_b);
	ft_printf("rrr\n");
}
