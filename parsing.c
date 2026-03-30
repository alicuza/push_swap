/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancuta <sancuta@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:27:29 by sancuta           #+#    #+#             */
/*   Updated: 2026/03/30 16:28:55 by sancuta          ###   ########.fr       */
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

size_t	sig_digits_strlen(const char *nbr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_isspace(nbr[i]))
		++i;
	if (ft_issign(nbr[i]))
		++i;
	while (nbr[i] == '0')
		++i;
	j = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		++j;
		++i;
	}
	return (j);
}

void	parse_argv(t_env *env, int argc, char **argv)
{
	int		i;
	size_t	len;

	i = 1;
	len = sig_digits_strlen(argv[1]);
	if (!(0 < len && len < 11))
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	env->node[1].nbr = validate_int(env, ft_atol(argv[1]), 1);
	env->node[1].next = 2;
	env->node[1].prev = argc - 1;
	while (++i < argc - 1)
	{
		len = sig_digits_strlen(argv[i]);
		if (!(0 < len && len < 10))
			cleanup(env->node, "Error\n", EXIT_FAILURE);
		env->node[i].nbr = validate_int(env, ft_atol(argv[i]), i);
		env->node[i].next = i + 1;
		env->node[i].prev = i - 1;
	}
	len = sig_digits_strlen(argv[i]);
	if (!(0 < len && len < 10))
		cleanup(env->node, "Error\n", EXIT_FAILURE);
	env->node[i].nbr = validate_int(env, ft_atol(argv[i]), i);
	env->node[i].next = 1;
	env->node[i].prev = argc - 2;
}
