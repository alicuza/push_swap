/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:04:26 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/26 12:16:34 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 3)
		return (1);
	env = init_env();
	parse_argv(env, argv);
}

t_env	init_env(void)
{
	t_env	e;

	e = (t_env){0};
	env->node_cnt = argc - 1;
	env->node = malloc(argc * sizeof(t_node));
	if (!env->node)
		just_error();
	env->stack_a = 0;
	env->stack_b = -1;
	return (e);
}

void	parse_argv(t_env *env, char **argv)
{
	size_t	i;

	i = 0;
	while (i < node_cnt)
	{
		node[i].nbr = ft_atoi(argv[i]);
	}
}
