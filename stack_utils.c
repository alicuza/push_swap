/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:15:02 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 10:36:31 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_node *node, t_stack_idx head)
{
	t_stack_idx	cur;
	size_t		i;

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

void	print_stack(t_node *node, t_stack_idx head)
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
