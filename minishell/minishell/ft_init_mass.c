/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:04:30 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 17:14:18 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_params(t_parser *parser)
{
	parser->params.dquotas = 0;
	parser->params.quotas = 0;
	parser->params.semicolon = 0;
	parser->params.commands = NULL;
	parser->params.commandquan = 0;
	parser->lenlen = 0;
	parser->params.flag_govna = 0;
	parser->params.col_pipe = 0;
	parser->params.flagsp = NULL;
	parser->params.col_redir = 0;
	parser->params.flagsr = NULL;
	parser->params.starmass = NULL;
	parser->mass_for_names = NULL;
	parser->dmss = 0;
	parser->fl = 0;
}

void	ft_init_commands(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.commands[i] != NULL)
	{
		parser->params.commands[i] = NULL;
		i++;
	}
}

void	ft_init_cmdtmp(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.cmdtmp[i] != NULL)
	{
		parser->params.cmdtmp[i] = NULL;
		i++;
	}
}

void	ft_replace_mass(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.cmdtmp[i] != NULL)
	{
		if (!(parser->params.commands[i] = (char *)malloc(sizeof(char)
			* (ft_strlen(parser->params.cmdtmp[i]) + 1))))
			ft_endparser(parser, 1);
		ft_strlcpy(parser->params.commands[i], parser->params.cmdtmp[i],
			(ft_strlen(parser->params.cmdtmp[i]) + 1));
		i++;
	}
}

void	ft_elsefree(int ret_val, char **read_line)
{
	if (ret_val < 1)
	{
		free(*read_line);
		*read_line = NULL;
	}
}
