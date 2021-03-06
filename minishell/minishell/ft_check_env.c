/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:05:49 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 18:27:44 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_env_del(t_parser *parser, int *i, int *j)
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
			parser->params.col_pipe++;
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			parser->params.col_redir++;
		*i += 1;
		*j += 1;
	}
}

void	ft_els_check1(int *k, t_parser *parser)
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

void	ft_check_env_del1(int *k, t_parser *parser, char **search)
{
	int j;

	j = 0;
	ft_els_check1(k, parser);
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

int		ft_check_ques1(t_parser *parser, char **search, char **str, int *kk)
{
	if ((*search)[0] == '?')
	{
		(*str) = ft_itoa(parser->dollar);
		*kk = ft_strlen((*str));
		free((*search));
		free((*str));
		return (1);
	}
	return (0);
}

int		ft_check_env(t_parser *parser, int *i, char **envp)
{
	int		j;
	int		k;
	char	*search;
	int		kk;
	char	*str;

	j = 0;
	k = *i;
	kk = 0;
	ft_check_env_del(parser, i, &j);
	if (!(search = (char *)malloc(sizeof(char) * (j + 2))))
		ft_endparser(parser, 1);
	search[j + 1] = '\0';
	ft_check_env_del1(&k, parser, &search);
	if (ft_check_ques1(parser, &search, &str, &kk) == 1)
		return (kk);
	j = 0;
	while (envp[j] != NULL)
	{
		if (ft_zikl1(&search, &kk, envp[j]) == 1)
			return (ft_skok_tam(envp[j], kk));
		j++;
	}
	ft_check_qual1(&search, parser, &kk);
	return (kk);
}
