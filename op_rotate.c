/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:25:55 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 14:09:54 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node *node, t_stack_idx *head)
{
	if (node[*head].next == *head)
		return (0);
	*head = node[*head].next;
	return (1);
}

void	ra(t_env *env)
{
	if (rotate(env->node, &env->head_a))
		ft_printf("ra\n");
}

void	rb(t_env *env)
{
	if (rotate(env->node, &env->head_b))
		ft_printf("rb\n");
}

void	rr(t_env *env)
{
	if (stack_len(env->node, env->head_a) < 2
		|| stack_len(env->node, env->head_b) < 2)
		return ;
	rotate(env->node, &env->head_a);
	rotate(env->node, &env->head_b);
	ft_printf("rr\n");
}
