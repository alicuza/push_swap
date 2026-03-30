/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:27:29 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 10:33:14 by sancuta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_int(t_env *env, long n, int idx)
{
	int	i;
	int	int_n;

	if (INT_MIN > n || n > INT_MAX)
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	int_n = (int)n;
	i = 1;
	while (i < idx)
	{
		if (int_n == env->node[i].nbr)
			cleanup(env->node, "Error\n", EXIT_FAILURE);
		i++;
	}
	return (int_n);
}

void	parse_argv(t_env *env, int argc, char **argv)
{
	int	i;

	if (ft_strlen(argv[1]) > 12 || !ft_is_nbr_str(argv[1]))
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	env->node[1].nbr = validate_int(env, ft_atol(argv[1]), 1);
	env->node[1].next = 2;
	env->node[1].prev = argc - 1;
	i = 1;
	while (++i < argc - 1)
	{
		if (ft_strlen(argv[i]) > 12 || !ft_is_nbr_str(argv[i]))
			cleanup(env->node, "Error\n", EXIT_FAILURE);
		env->node[i].nbr = validate_int(env, ft_atol(argv[i]), i);
		env->node[i].next = i + 1;
		env->node[i].prev = i - 1;
	}
	if (ft_strlen(argv[argc - 1]) > 12 || !ft_is_nbr_str(argv[argc - 1]))
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	env->node[argc - 1].nbr = validate_int(env, ft_atol(argv[argc - 1]),
			argc - 1);
	env->node[argc - 1].next = 1;
	env->node[argc - 1].prev = argc - 2;
}
