/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:23:08 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 01:24:26 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node, t_stack_idx *head)
{
	t_stack_idx	first;
	t_stack_idx	second;
	size_t		len;

	len = stack_len(node, *head);
	if (len < 2)
		return ;
	first = *head;
	second = node[first].next;
	node[node[second].next].prev = first;
	node[first].next = node[second].next;
	node[node[first].prev].next = second;
	node[second].prev = node[first].prev;
	node[second].next = first;
	node[first].prev = second;
	*head = second;
}

void	sa(t_env *env)
{
	swap(env->node, &env->head_a);
	ft_printf("sa\n");
}

void	sb(t_env *env)
{
	swap(env->node, &env->head_b);
	ft_printf("sb\n");
}

void	ss(t_env *env)
{
	swap(env->node, &env->head_a);
	swap(env->node, &env->head_b);
	ft_printf("ss\n");
}
