/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:15:24 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 14:37:09 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_pipes_and_redirs(char *str, t_parser *parser)
{
	ft_pipes_and_redirs3(parser, str);
	parser->mass.strings =
	(char **)malloc(sizeof(char *) * (parser->mass.j + 1));
	parser->mass.strings[parser->mass.j] = NULL;
	ft_pipes_and_redirs2(parser, &str);
	parser->mass.strings[parser->mass.l] =
	(char *)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	ft_strlcpy(parser->mass.strings[parser->mass.l], str, ft_strlen(str) + 1);
	parser->mass.strings[parser->mass.l][ft_strlen(str)] = '\0';
	parser->params.index = 0;
	return (parser->mass.strings);
}

void	ft_pipes_and_redirs2(t_parser *parser, char **str)
{
	while ((*str)[parser->mass.i] && parser->mass.l < parser->mass.j)
	{
		if ((*str)[parser->mass.i] == '|')
		{
			if (parser->params.flagsp[parser->params.index] == '0')
			{
				parser->mass.i++;
				parser->mass.strings[parser->mass.l] =
				(char *)malloc(sizeof(char *) * (parser->mass.i));
				ft_strlcpy(parser->mass.strings[parser->mass.l],
				(*str), parser->mass.i);
				parser->mass.strings[parser->mass.l][parser->mass.i] = '\0';
				(*str) += parser->mass.i;
				parser->mass.i = 0;
				parser->mass.l++;
			}
			parser->params.index++;
		}
		parser->mass.i++;
	}
}

void	ft_pipes_and_redirs3(t_parser *parser, char *str)
{
	parser->mass.i = 0;
	parser->mass.k = 0;
	parser->mass.j = 1;
	parser->mass.l = 0;
	while (str[parser->mass.i])
	{
		if (str[parser->mass.i] == '|')
		{
			if (parser->params.flagsp[parser->params.index] == '0')
				parser->mass.j++;
			parser->params.index++;
		}
		parser->mass.i++;
	}
	parser->params.index = 0;
	parser->mass.i = 0;
}

int		ft_smth(char *str)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
			return (flag);
		if (str[i] != ' ')
			flag = 1;
		i++;
	}
	return (flag);
}

int		ft_check_if_builtin(char **str, char ***envp,
		t_parser *parser, int tmp_fd1)
{
	int ret;

	ret = 0;
	if (ret == 0)
		ret = ft_echo(*str, parser);
	if (ret == 0)
		ret = ft_pwd(*str, parser);
	if (ret == 0)
		ret = ft_cd(*str, envp, parser);
	if (ret == 0)
		ret = ft_env(*envp, *str, parser);
	if (ret == 0)
		ret = ft_export(envp, *str, parser);
	if (ret == 0)
		ret = ft_unset(envp, *str, parser);
	if (ret == 0)
		ret = ft_exit(*str, parser);
	if (ret == 0)
		ret = ft_exec(*envp, *str, parser);
	if (ret == 0)
		ret = ft_defaults(*str, *envp, 1, parser);
	if (ret == 0)
		ret = ft_not_found(*str, parser, tmp_fd1);
	return (ret);
}
