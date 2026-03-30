/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:04:26 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 11:20:26 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_nodes(t_env *env, int argc)
{
	env->node = malloc(argc * sizeof(t_node));
	if (!env->node)
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	ft_memset(env->node, 0, argc * sizeof(t_node));
}

t_env	init_env(int argc)
{
	t_env	env;

	env = (t_env){0};
	init_nodes(&env, argc);
	env.head_a = 1;
	env.head_b = 0;
	return (env);
}

int	is_start_sorted(t_env env, int argc)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (env.node[i].nbr < env.node[i - 1].nbr)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc <= 2)
		return (0);
	env = init_env(argc);
	parse_argv(&env, argc, argv);
	if (is_start_sorted(env, argc))
		cleanup(env.node, "", EXIT_SUCCESS);
	assign_rank(&env);
	if (argc < 6)
		mini_sort(&env, argc - 1);
	else
	{
		radix_sort(&env, argc - 1);
		rotate_to_top(&env, find_min_pos(&env),
			argc - 1);
	}
	cleanup(env.node, "", EXIT_SUCCESS);
}
