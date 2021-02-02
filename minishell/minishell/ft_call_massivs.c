/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_massivs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:35:39 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 16:33:36 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_call_flags(t_parser *parser)
{
	int i;

	i = 0;
	if (parser->params.flagsp != NULL)
	{
		free(parser->params.flagsp);
		parser->params.flagsp = NULL;
	}
	if (!(parser->params.flagsp = (char *)malloc(sizeof(char)
		* (parser->params.col_pipe + 1))))
		ft_endparser(parser, 1);
	while (i < parser->params.col_pipe)
	{
		parser->params.flagsp[i] = '\0';
		i++;
	}
	parser->params.flagsp[i] = '\0';
	parser->params.col_pipe = 0;
}

void	ft_call_flags_red(t_parser *parser)
{
	int i;

	i = 0;
	if (parser->params.flagsr != NULL)
	{
		free(parser->params.flagsr);
		parser->params.flagsr = NULL;
	}
	if (!(parser->params.flagsr = (char *)malloc(sizeof(char)
		* (parser->params.col_redir + 1))))
		ft_endparser(parser, 1);
	while (i < parser->params.col_redir)
	{
		parser->params.flagsr[i] = '\0';
		i++;
	}
	parser->params.flagsr[i] = '\0';
	parser->params.col_redir = 0;
}

void	ft_call_starmass(t_parser *parser)
{
	int i;

	i = 0;
	if (parser->params.starmass != NULL)
	{
		free(parser->params.starmass);
		parser->params.starmass = NULL;
	}
	if (!(parser->params.starmass = (char *)malloc(sizeof(char)
		* (parser->mas_col + 1))))
		ft_endparser(parser, 1);
	while (i < parser->mas_col)
	{
		parser->params.starmass[i] = '\0';
		i++;
	}
	parser->params.starmass[i] = '\0';
	parser->mas_col = 0;
}

void	ft_callred_quot(t_parser *parser)
{
	int i;

	i = 0;
	if (!(parser->mass_for_names = (char **)malloc(sizeof(char *)
		* (parser->quanred + 2))))
		ft_endparser(parser, 1);
	while (i <= parser->quanred)
	{
		parser->mass_for_names[i] = NULL;
		i++;
	}
	parser->mass_for_names[i] = NULL;
}

void	ft_fill_home(t_parser *parser, char **envp, int *m)
{
	int j;

	j = 0;
	while (envp[j] != NULL)
	{
		if (ft_strncmp("HOME=", envp[j], 5) == 0)
		{
			ft_skok_tam1(envp[j], 5, parser, m);
			return ;
		}
		j++;
	}
}
