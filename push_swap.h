/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:47:24 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/26 16:25:41 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/arena/arena.h"
# include <limits.h>

typedef size_t head;
typedef size_t idx;

typedef struct s_node
{
	idx	next_idx;
	idx	prev_idx;
	int	nbr;
}	t_node;

typedef struct s_env
{
	t_node	*node;
	head	stack_a;
	head	stack_b;
}	t_env;

#endif
