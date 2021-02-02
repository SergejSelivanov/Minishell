/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oldpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:32:44 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 18:45:45 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_oldpwd_to_end(char ***envp, char *act_path, t_parser *parser)
{
	int		i;
	char	*oldpwd;
	char	*pwd;

	i = 0;
	pwd = ft_find_pwd(*envp);
	if (pwd != NULL)
	{
		oldpwd = ft_strjoin("OLDPWD=", pwd);
		while ((*envp)[i])
			i++;
		parser->params.string_to_free[parser->params.string_index] =
		ft_strdup(oldpwd);
		free(oldpwd);
		(*envp)[i] = parser->params.string_to_free[parser->params.string_index];
		parser->params.string_index++;
		parser->params.string_to_free[parser->params.string_index] = NULL;
		(*envp)[i + 1] = NULL;
	}
	else
	{
		oldpwd = ft_strjoin("OLDPWD=", act_path);
		ft_if_there_is_pwd(envp, parser, &oldpwd);
	}
	free(pwd);
}

void	ft_if_there_is_pwd(char ***envp, t_parser *parser, char **oldpwd)
{
	int i;

	i = 0;
	while ((*envp)[i])
		i++;
	parser->params.string_to_free[parser->params.string_index] =
	ft_strdup(*oldpwd);
	free(*oldpwd);
	(*envp)[i] = parser->params.string_to_free[parser->params.string_index];
	parser->params.string_index++;
	parser->params.string_to_free[parser->params.string_index] = NULL;
	(*envp)[i + 1] = NULL;
}

void	ft_make_oldpwd_nothing(char **envp)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "OLDPWD", 6)) &&
		(envp[i][6] == '=' || !(envp[i][6])))
		{
			envp[i] = "OLDPWD";
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
	{
		envp[i] = "OLDPWD";
		envp[i + 1] = NULL;
	}
}

void	ft_change_oldpwd(char ***envp, int i, t_parser *parser)
{
	char *oldpwd;
	char *pwd;

	pwd = ft_find_pwd(*envp);
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	free(pwd);
	parser->params.string_to_free[parser->params.string_index] =
	ft_strdup(oldpwd);
	free(oldpwd);
	(*envp)[i] = parser->params.string_to_free[parser->params.string_index];
	parser->params.string_index++;
	parser->params.string_to_free[parser->params.string_index] = NULL;
}

int		ft_find_oldpwd(char **envp, int flag)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp("OLDPWD", envp[i], 6)) && (envp[i][6] == '=' ||
		!(envp[i][6])) && flag == 2)
			return (i);
		if (!(ft_strncmp("OLDPWD=", envp[i], 7)) && flag == 1)
			return (i);
		i++;
	}
	return (-1);
}
