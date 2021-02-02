/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:03:44 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 18:19:40 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_env2_del(t_parser *parser, int *i, int *j)
{
	if (parser->crtline[*i] == '_' || ft_isalpha(parser->crtline[*i]) == 0)
	{
		if (parser->crtline[*i] != '"' && parser->crtline[*i] != '\''
			&& parser->crtline[*i] != '=')
		{
			*i += 1;
			*j += 1;
		}
		return ;
	}
	while (parser->crtline[*i] != '$' && parser->crtline[*i] != ' '
		&& parser->crtline[*i] != '\0'
		&& parser->crtline[*i] != '"' && parser->crtline[*i] != '\\'
		&& parser->crtline[*i] != '"' && parser->crtline[*i] != '\''
		&& parser->crtline[*i] != ';')
	{
		if (parser->crtline[*i] == '|')
			parser->params.col_pipe++;
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			parser->params.col_redir++;
		*i += 1;
		*j += 1;
	}
}

void	ft_check_env2_del1(int *k, t_parser *parser, char **search)
{
	int j;

	j = 0;
	if (parser->crtline[*k] == '_' || ft_isalpha(parser->crtline[*k]) == 0)
	{
		if (parser->crtline[*k] != '"' && parser->crtline[*k] != '\''
		&& parser->crtline[*k] != '=')
		{
			(*search)[j] = parser->crtline[*k];
			*k += 1;
			j += 1;
		}
		(*search)[j] = '=';
		return ;
	}
	while (parser->crtline[*k] != '$' && parser->crtline[*k] != ' '
		&& parser->crtline[*k] != '\0' && parser->crtline[*k] != '"'
		&& parser->crtline[*k] != '\\' && parser->crtline[*k] != '"'
		&& parser->crtline[*k] != '\'' && parser->crtline[*k] != ';')
	{
		(*search)[j] = parser->crtline[*k];
		j++;
		*k += 1;
	}
	(*search)[j] = '=';
}

int		ft_check_ques(char **search, int *kk, t_parser *parser)
{
	if ((*search)[0] == '?')
	{
		*kk = ft_strlen(ft_itoa(parser->dollar));
		free((*search));
		return (1);
	}
	return (0);
}

void	ft_ravno(int *kk, char **search)
{
	if (ft_strlen((*search)) == 1 && (*search)[0] == '=')
	{
		*kk += 1;
	}
	free((*search));
}

int		ft_check_env2(t_parser *parser, int *i, char **envp)
{
	int		j;
	int		k;
	char	*search;
	int		kk;

	j = 0;
	k = *i;
	kk = 0;
	ft_check_env2_del(parser, i, &j);
	if (!(search = (char *)malloc(sizeof(char) * (j + 2))))
		ft_endparser(parser, 1);
	search[j + 1] = '\0';
	ft_check_env2_del1(&k, parser, &search);
	if (ft_check_ques(&search, &kk, parser) == 1)
		return (kk);
	j = 0;
	while (envp[j] != NULL)
	{
		if (ft_zikl(&search, envp[j], &kk) == 1)
			return (ft_skok_tam(envp[j], kk));
		j++;
	}
	ft_ravno(&kk, &search);
	return (kk);
}
