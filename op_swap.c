/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:23:08 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 09:03:37 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node *node, t_stack_idx *head)
{
	t_stack_idx	first;
	t_stack_idx	second;
	size_t		len;

	len = stack_len(node, *head);
	if (len < 2)
		return (0);
	if (len == 2)
	{
		rotate(node, head);
		return (1);
	}
	first = *head;
	second = node[first].next;
	node[node[second].next].prev = first;
	node[first].next = node[second].next;
	node[node[first].prev].next = second;
	node[second].prev = node[first].prev;
	node[second].next = first;
	node[first].prev = second;
	*head = second;
	return (1);
}

void	sa(t_env *env)
{
	if (swap(env->node, &env->head_a))
		ft_printf("sa\n");
}

void	sb(t_env *env)
{
	if (swap(env->node, &env->head_b))
		ft_printf("sb\n");
}

void	ss(t_env *env)
{
	if (swap(env->node, &env->head_a) && swap(env->node, &env->head_b))
		ft_printf("ss\n");
}
