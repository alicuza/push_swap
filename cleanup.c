/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:16:37 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/29 13:38:40 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_node *nodes)
{
	if (nodes)
	{
		free(nodes);
		nodes = NULL;
	}
	just_error();
	exit(1);
}
