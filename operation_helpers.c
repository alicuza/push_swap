/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:03:37 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/29 15:57:29 by sancuta          ###   ########.fr       */
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
		ft_printf("stack empty\n");
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
	size_t		len;

	len = stack_len(node, *head);
	if (len < 2)
		return ;
/*	TODO: to be documented, how this check is unnecessary if the order
	if the order of relinking is kept proper.
	RULE: any line that writes through an aliased pointer
	must come after all lines that read through it!
	if (len == 2)
	{
		rotate(node, head);
		return ;
	}
*/	first = *head;
	second = node[first].next;
	node[node[second].next].prev = first;
	node[first].next = node[second].next;
	node[node[first].prev].next = second;
	node[second].prev = node[first].prev;
	node[second].next = first;
	node[first].prev = second;
	*head = second;
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
	t_stack_idx	target;

	target = *src;
	pop_node(node, src);
	push_node(node, dest, target);
}

void	rotate(t_node *node, t_stack_idx *head)
{
	*head = node[*head].next;
}

void	reverse_rotate(t_node *node, t_stack_idx *head)
{
	*head = node[*head].prev;
}
