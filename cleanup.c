/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:16:37 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 08:43:56 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_node *nodes, char *msg, int status)
{
	if (nodes)
	{
		free(nodes);
		nodes = NULL;
	}
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(status);
}
