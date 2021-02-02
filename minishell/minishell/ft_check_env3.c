/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:58:37 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 18:44:42 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_env3_del(t_parser *parser, int *i, int *j)
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
			ft_fill_flags(parser, '1');
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			ft_fill_flags_red(parser, '0');
		*i += 1;
		*j += 1;
	}
}

void	ft_check_env3_del1(int *k, t_parser *parser, char **search)
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

void	ft_check_env31(t_parser *parser, char **search, int *m)
{
	if (ft_strlen((*search)) == 1 && (*search)[0] == '=')
	{
		parser->params.commands[parser->lenlen][*m] = '$';
		*m += 1;
	}
	free((*search));
}

int		ft_check_env32(t_parser *parser, char **search, int *m)
{
	if ((*search)[0] == '?')
	{
		ft_fill_dollar(parser, m);
		free((*search));
		return (1);
	}
	return (0);
}

void	ft_check_env3(t_parser *parser, int *i, char **envp, int *m)
{
	int		j;
	int		k;
	char	*search;

	j = 0;
	k = *i;
	ft_check_env3_del(parser, i, &j);
	if (!(search = (char *)malloc(sizeof(char) * (j + 2))))
		ft_endparser(parser, 1);
	search[j + 1] = '\0';
	ft_check_env3_del1(&k, parser, &search);
	if (ft_check_env32(parser, &search, m) == 1)
		return ;
	j = 0;
	while (envp[j] != NULL)
	{
		if (ft_strncmp(search, envp[j], ft_strlen(search)) == 0)
		{
			ft_check_env3_dop(parser, envp[j], &search, m);
			return ;
		}
		j++;
	}
	ft_check_env31(parser, &search, m);
	return ;
}
