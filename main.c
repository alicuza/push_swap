/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:04:26 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/27 17:03:21 by sancuta          ###   ########.fr       */
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
		just_error();
	int_n = (int)n;
	i = 0;
	while (i < idx)
	{
		if (int_n == env->node[idx].nbr)
			just_error();
		i++;
	}
	return (int_n);
}

void	parse_argv(t_env *env, int argc, char **argv)
{
	int	i;

	if (ft_strlen(argv[1]) > 12)
		just_error();
	env->node[1].nbr = validate_int(env, ft_atol(argv[1]), 1);
	env->node[1].next = 2;
	env->node[1].prev = argc - 1;
	i = 1;
	while (++i < argc - 1)
	{
		if (ft_strlen(argv[i]) > 12)
			just_error();
		env->node[i].nbr = validate_int(env, ft_atol(argv[i]), i);
		env->node[i].next = i + 1;
		env->node[i].prev = i - 1;
	}
	if (ft_strlen(argv[argc - 1]) > 12)
		just_error();
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

#include <stdio.h> // DEBUG
int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 3)
		return (1);
	env = init_env(argc);
	parse_argv(&env, argc, argv);
//	for (int i = 0; i < argc; i++) // DEBUG
//		printf("node[%d] = %d\n", i, env.node[i].nbr); // DEBUG
	
	ft_printf("stack is%ssorted\n", is_stack_sorted(env, argc) ? " " : " not ");
	ft_printf("\nswapping a\n");
	print_stack(env.node, env.head_a);
	sa(&env);
	ft_printf("\nafter swapping:\n");
	print_stack(env.node, env.head_a);
	ft_printf("\npushing to b\n");
	printf("\nstack A len = %zu\n", stack_len(env.node, env.head_a));
	printf("\nstack B len = %zu\n", stack_len(env.node, env.head_b));
	pb(&env);
	ft_printf("\nafter pushing:\n");
	printf("\nstack A len = %zu\n", stack_len(env.node, env.head_a));
	printf("\nstack B len = %zu\n", stack_len(env.node, env.head_b));
	ft_printf("\nstack A:\n\n");
	print_stack(env.node, env.head_a);
	ft_printf("\nstack B:\n\n");
	print_stack(env.node, env.head_b);
	ft_printf("\nexecuting: pb pb sa pb sb pa ss\n\n");
	pb(&env), pb(&env), sa(&env), pb(&env), sb(&env), pa(&env), ss(&env);
	ft_printf("\nafter operations:\n");
	printf("\nstack A len = %zu\n", stack_len(env.node, env.head_a));
	printf("\nstack B len = %zu\n", stack_len(env.node, env.head_b));
	ft_printf("\nstack A:\n\n");
	print_stack(env.node, env.head_a);
	ft_printf("\nstack B:\n\n");
	print_stack(env.node, env.head_b);

	return (0);
}
