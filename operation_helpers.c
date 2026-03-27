/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:03:37 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/27 13:10:25 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_node *node, t_stack_idx head)
{
	t_stack_idx	cur;
	size_t	i;

	if (!node[head].next)
		return (0);
	cur = head;
	i = 1;
	while (node[cur].next != head)
	{
		++i;
		cur = node[cur].next;
	}
	return (i);
}

void print_stack(t_node *node, t_stack_idx head)
{
	t_stack_idx	cur;

	if (!stack_len(node, head))
	{
		write(1, "stack empty", 11);
		return ;
	}
	cur = head;
	ft_printf("node[%d] = {\n\tnbr = %d;\n\tnext = %u;\n\tprev = %u;\n}\n",
			cur, node[cur].nbr, node[cur].next, node[cur].prev);
	cur = node[cur].next;
	while (cur != head)
	{
		ft_printf("node[%d] = {\n\tnbr = %d;\n\tnext = %u;\n\tprev = %u;\n}\n",
				cur, node[cur].nbr, node[cur].next, node[cur].prev);
		cur = node[cur].next;
	}
}

void	swap(t_node *node, t_stack_idx *head)
{
	t_stack_idx	first;
	t_stack_idx	second;

	if (stack_len(node, *head) < 2)
		return ;
	first = *head;
	second = node[first].next;
	node[node[first].prev].next = second;
	node[node[second].next].prev = first;
	node[second].prev = node[first].prev;
	node[first].next = node[second].next;
	node[second].next = first;
	node[first].prev = second;
	*head = second;
}

/*void	push(t_node *node, t_stack_idx head_1, t_stack_idx head_2)
{
	
}*/
