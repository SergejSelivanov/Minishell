/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_for_env_func.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:11:57 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 19:21:37 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_find_in_env(char **envp, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j])
			j++;
		if (!(ft_strncmp(envp[i], str, ft_strlen(str))) &&
		!(ft_strncmp(envp[i], str, j)))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_symb_before_eq(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i])) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_path(char **envp)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
			return (1);
		i++;
	}
	return (0);
}

void	ft_make_free_str(t_parser *parser)
{
	parser->params.string_index = 0;
	parser->params.string_to_free = (char **)malloc(sizeof(char *) * 1000);
	parser->params.string_to_free[0] = NULL;
}
