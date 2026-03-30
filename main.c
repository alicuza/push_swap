/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:04:26 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 01:34:02 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_nodes(t_env *env, int argc)
{
	env->node = malloc(argc * sizeof(t_node));
	if (!env->node)
		just_error();
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
int	validate_int(t_env *env, long n, int idx)
{
	int	i;
	int	int_n;

	if (INT_MIN > n || n > INT_MAX)
		cleanup(env->node);
	int_n = (int)n;
	i = 1;
	while (i < idx)
	{
		if (int_n == env->node[i].nbr)
			cleanup(env->node);
		i++;
	}
	return (int_n);
}

void	parse_argv(t_env *env, int argc, char **argv)
{
	int	i;

	if (ft_strlen(argv[1]) > 12 || !ft_is_nbr_str(argv[1]))
		cleanup(env->node);
	env->node[1].nbr = validate_int(env, ft_atol(argv[1]), 1);
	env->node[1].next = 2;
	env->node[1].prev = argc - 1;
	i = 1;
	while (++i < argc - 1)
	{
		if (ft_strlen(argv[i]) > 12 || !ft_is_nbr_str(argv[i]))
			cleanup(env->node);
		env->node[i].nbr = validate_int(env, ft_atol(argv[i]), i);
		env->node[i].next = i + 1;
		env->node[i].prev = i - 1;
	}
	if (ft_strlen(argv[argc - 1]) > 12 || !ft_is_nbr_str(argv[argc - 1]))
		cleanup(env->node);
	env->node[argc - 1].nbr = validate_int(env, ft_atol(argv[argc - 1]),
			argc - 1);
	env->node[argc - 1].next = 1;
	env->node[argc - 1].prev = argc - 2;
}

int	is_stack_sorted(t_env env, int argc)
// TODO: consider replacing this function in main with a LIS (Longest Increasing
// Subsequence) function if reasonable. If the LIS I find is as long as the
// stack, I know the stack is sorted. Should I use LIS to also push from b to a?
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (env.node[i].nbr < env.node[i - 1].nbr)
			return (0);
		++i;
	}
	return (1);
}

//#include <stdio.h> // DEBUG
int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 3)
		return (1);
	env = init_env(argc);
	parse_argv(&env, argc, argv);
	if (is_stack_sorted(env, argc))
	{
		if (env.node)
		{
			free(env.node);
			env.node = NULL;
		}
		return (0);
	}
	compress_values(&env);
	if (argc < 6)
		mini_sort(&env, argc - 1);
	else
		radix_sort(&env, argc - 1);
	return (0);
}
