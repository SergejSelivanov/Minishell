/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:12:33 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 18:58:04 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pwd(char *str, t_parser *parser)
{
	char	path[PATH_MAX + 1];

	if (!(ft_strncmp("pwd", str, 3)) && (*(str + 3) == ' ' || !(*(str + 3))))
	{
		getcwd(path, PATH_MAX + 1);
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
		parser->dollar = 0;
		return (1);
	}
	return (0);
}

char	*ft_find_pwd(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (envp[i])
	{
		if (!(ft_strncmp("PWD=", envp[i], 4)))
		{
			ret = ft_strdup(envp[i] + 4);
			break ;
		}
		i++;
	}
	return (ret);
}

void	ft_change_pwd(char ***envp, char *act_path, t_parser *parser)
{
	int		i;
	char	*pwd;
	int		flag;

	flag = 0;
	i = 0;
	while ((*envp)[i])
	{
		if (!(ft_strncmp("PWD", (*envp)[i], 3)) &&
		((*envp)[i][3] == '=' || !((*envp)[i][3])))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
	{
		pwd = ft_strjoin("PWD=", act_path);
		parser->params.string_to_free[parser->params.string_index] =
		ft_strdup(pwd);
		free(pwd);
		ft_pwd_eq_envp(parser, envp, i);
	}
}

void	ft_pwd_eq_envp(t_parser *parser, char ***envp, int i)
{
	(*envp)[i] = parser->params.string_to_free[parser->params.string_index];
	parser->params.string_index++;
	parser->params.string_to_free[parser->params.string_index] = NULL;
}
