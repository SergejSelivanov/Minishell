/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cn_ss_crn_quot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:12:24 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 17:59:31 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_next(t_parser *parser, int i)
{
	if (parser->crtline[i + 1] == '$' || parser->crtline[i + 1] == '\\'
		|| parser->crtline[i + 1] == '"' || parser->crtline[i + 1] == '`')
		return (1);
	return (0);
}

void	ft_calloc_red_name(t_parser *parser)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (parser->mass_for_names[j] != NULL)
		j++;
	if (!(parser->mass_for_names[j] = (char *)malloc(sizeof(char)
		* (parser->flag_red_name_col + 1))))
		ft_endparser(parser, 1);
	while (i < parser->flag_red_name_col)
	{
		parser->mass_for_names[j][i] = '\0';
		i++;
	}
	parser->mass_for_names[j][i] = '\0';
	parser->flag_red_name_col = 0;
}

void	ft_check_usl(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == '\\' && ft_check_next(parser, *i) == 1)
		*i += 1;
	if (parser->crtline[*i] == '|')
		parser->params.col_pipe++;
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
		parser->params.col_redir++;
	*i += 1;
}

void	ft_in_quot(t_parser *parser, int *i, int *j, char **envp)
{
	int col;

	col = 0;
	*i += 1;
	while (parser->crtline[*i] != '"' && parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '$')
		{
			*i += 1;
			col = ft_check_env2(parser, i, envp);
			ft_in_quot_dop(parser, col, j);
			continue ;
		}
		ft_check_usl(parser, i);
		*j += 1;
		parser->mas_col++;
		if (parser->flag1 == 1)
			parser->flag_red_name_col++;
	}
	if (parser->crtline[*i] == '\0')
	{
		parser->flagvih = 1;
		return ;
	}
	*i += 1;
}

void	ft_in_quot1(t_parser *parser, int *i, int *j)
{
	*i += 1;
	while (parser->crtline[*i] != '\'' && parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '|')
			parser->params.col_pipe++;
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			parser->params.col_redir++;
		*i += 1;
		*j += 1;
		parser->mas_col++;
		if (parser->flag1 == 1)
			parser->flag_red_name_col++;
	}
	if (parser->crtline[*i] == '\0')
	{
		parser->flagvih = 1;
		return ;
	}
	*i += 1;
}
