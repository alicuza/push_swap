/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:47:24 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/27 14:26:42 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/arena/arena.h"
# include <limits.h>

typedef size_t			t_stack_idx;
typedef size_t			t_node_idx;
typedef unsigned int	t_uint;

typedef struct s_node
{
	t_node_idx	next;
	t_node_idx	prev;
	int			nbr;
}	t_node;

typedef struct s_env
{
	t_node		*node;
	t_stack_idx	head_a;
	t_stack_idx	head_b;
}	t_env;

size_t	stack_len(t_node *node, t_stack_idx head);
void	print_stack(t_node *node, t_stack_idx head);
void	swap(t_node *node, t_stack_idx *head);
void	sa(t_env *env);
void	sb(t_env *env);
void	ss(t_env *env);
void	push(t_node *node, t_stack_idx *dest, t_stack_idx *src);
void	pa(t_env *env);
void	pb(t_env *env);
#endif
