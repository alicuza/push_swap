/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:24:45 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 01:25:28 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *env)
{
	push(env->node, &env->head_a, &env->head_b);
	ft_printf("pa\n");
}

void	pb(t_env *env)
{
	push(env->node, &env->head_b, &env->head_a);
	ft_printf("pb\n");
}

void	pop_node(t_node *node, t_stack_idx *src)
{
	size_t src_len;

	src_len = stack_len(node, *src);
	if (!src_len)
		return ;
	if (src_len == 1)
	{
		*src = 0;
		return ;
	}
	node[node[*src].prev].next = node[*src].next;
	node[node[*src].next].prev = node[*src].prev;
	*src = node[*src].next;
}

void	push_node(t_node *node, t_stack_idx *dest, t_stack_idx src)
{
	if (!stack_len(node, *dest))
	{
		node[src].next = src;
		node[src].prev = src;
		*dest = src;
		return ;
	}
	node[src].next = *dest;
	node[src].prev = node[*dest].prev;
	node[node[*dest].prev].next = src;
	node[*dest].prev = src;
	*dest = src;
}

void	push(t_node *node, t_stack_idx *dest, t_stack_idx *src)
{
	t_stack_idx	old_src;

	old_src = *src;
	pop_node(node, src);
	push_node(node, dest, old_src);
}
