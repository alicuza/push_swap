/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:24:45 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 10:16:52 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *env)
{
	if (push(env->node, &env->head_a, &env->head_b))
		ft_printf("pa\n");
}

void	pb(t_env *env)
{
	if (push(env->node, &env->head_b, &env->head_a))
		ft_printf("pb\n");
}

int	pop_node(t_node *node, t_stack_idx *src)
{
	size_t src_len;

	src_len = stack_len(node, *src);
	if (!src_len)
		return (0);
	if (src_len == 1)
	{
		*src = 0;
		return (1);
	}
	node[node[*src].prev].next = node[*src].next;
	node[node[*src].next].prev = node[*src].prev;
	*src = node[*src].next;
	return (1);
}

int	push_node(t_node *node, t_stack_idx *dest, t_stack_idx src)
{
	if (!stack_len(node, *dest))
	{
		node[src].next = src;
		node[src].prev = src;
		*dest = src;
		return (1);
	}
	node[src].next = *dest;
	node[src].prev = node[*dest].prev;
	node[node[*dest].prev].next = src;
	node[*dest].prev = src;
	*dest = src;
	return (1);
}

int	push(t_node *node, t_stack_idx *dest, t_stack_idx *src)
{
	t_stack_idx	old_src;

	old_src = *src;
	if (pop_node(node, src) && push_node(node, dest, old_src))
		return (1);
	return (0);
}
