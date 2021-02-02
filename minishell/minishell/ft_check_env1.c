/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:04:53 by wjena             #+#    #+#             */
/*   Updated: 2020/12/28 18:18:03 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_env1_del(t_parser *parser, int *i, int *j)
{
	if (parser->crtline[*i] == '_' || ft_isalpha(parser->crtline[*i]) == 0)
	{
		if (parser->crtline[*i] != '"' && parser->crtline[*i] != '\''
			&& parser->crtline[*i] != '\0' && parser->crtline[*i] != '=')
		{
			*i += 1;
			*j += 1;
		}
		return ;
	}
	while (parser->crtline[*i] != '$' && parser->crtline[*i] != ' '
		&& parser->crtline[*i] != '\0' && parser->crtline[*i] != '\\'
		&& parser->crtline[*i] != '"' && parser->crtline[*i] != '\''
		&& parser->crtline[*i] != ';' && parser->crtline[*i] != '=')
	{
		if (parser->crtline[*i] == '|')
			ft_fill_flags(parser, '1');
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			ft_fill_flags_red(parser, '1');
		*i += 1;
		*j += 1;
	}
}

void	ft_els_check2(int *k, t_parser *parser)
{
	if (parser->crtline[*k] == '"' && parser->crtline[*(k) + 1] == '"')
		parser->params.flag_govna = 1;
	if (parser->crtline[*k] == '\'' && parser->crtline[*(k) + 1] == '\'')
		parser->params.flag_govna = 1;
	if (parser->crtline[*k] == '"' && parser->crtline[*(k) + 1] != '"')
		parser->params.flag_govna = 1;
	if (parser->crtline[*k] == '\'' && parser->crtline[*(k) + 1] != '\'')
		parser->params.flag_govna = 1;
}

void	ft_check_env1_del1(int *k, t_parser *parser, char **search)
{
	int j;

	j = 0;
	ft_els_check2(k, parser);
	if (parser->crtline[*k] == '_' || ft_isalpha(parser->crtline[*k]) == 0)
	{
		if (parser->crtline[*k] != '"' && parser->crtline[*k] != '\''
			&& parser->crtline[*k] != '\0' && parser->crtline[*k] != '=')
			ft_check_enc_del1_dop(parser, k, search, &j);
		(*search)[j] = '=';
		return ;
	}
	while (parser->crtline[*k] != '$' && parser->crtline[*k] != ' '
		&& parser->crtline[*k] != '\0' && parser->crtline[*k] != '\\'
		&& parser->crtline[*k] != '"' && parser->crtline[*k] != '\''
		&& parser->crtline[*k] != ';' && parser->crtline[*k] != '=')
	{
		(*search)[j] = parser->crtline[*k];
		j++;
		*k += 1;
	}
	(*search)[j] = '=';
}

int		ft_check_ques2(t_parser *parser, char **search, int *m)
{
	if ((*search)[0] == '?')
	{
		ft_fill_dollar(parser, m);
		free((*search));
		return (1);
	}
	return (0);
}

void	ft_check_env1(t_parser *parser, int *i, char **envp, int *m)
{
	int		j;
	int		k;
	char	*search;

	j = 0;
	k = *i;
	ft_check_env1_del(parser, i, &j);
	if (!(search = (char *)malloc(sizeof(char) * (j + 2))))
		ft_endparser(parser, 1);
	search[j + 1] = '\0';
	ft_check_env1_del1(&k, parser, &search);
	j = 0;
	if (ft_check_ques2(parser, &search, m))
		return ;
	while (envp[j] != NULL)
	{
		if (ft_zikl3(parser, &search, envp[j], m) == 1)
			return ;
		j++;
	}
	ft_check_qual4(parser, &search, m);
	return ;
}
