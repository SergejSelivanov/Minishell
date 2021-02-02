/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc_dmss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:08:04 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 16:36:34 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_mass(t_parser *parser)
{
	parser->params.commandquan += 1;
	if (!(parser->params.commands = (char **)malloc(sizeof(char *)
		* parser->params.commandquan)))
		ft_endparser(parser, 1);
	parser->params.commands[parser->params.commandquan - 1] = NULL;
	ft_init_commands(parser);
}

void	ft_free_commands(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.commands[i] != NULL)
	{
		free(parser->params.commands[i]);
		parser->params.commands[i] = NULL;
		i++;
	}
	free(parser->params.commands);
	parser->fl = i;
	parser->params.commands = NULL;
}

void	ft_free_tmp(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.cmdtmp[i] != NULL)
	{
		free(parser->params.cmdtmp[i]);
		parser->params.cmdtmp[i] = NULL;
		i++;
	}
	free(parser->params.cmdtmp);
	parser->params.cmdtmp = NULL;
}

void	ft_fill_tmp(t_parser *parser)
{
	if (!(parser->params.cmdtmp = (char **)malloc(sizeof(char *)
		* parser->params.commandquan)))
		ft_endparser(parser, 1);
	parser->params.cmdtmp[parser->params.commandquan - 1] = NULL;
	ft_init_cmdtmp(parser);
}

void	ft_replace_tmp(t_parser *parser)
{
	int i;

	i = 0;
	while (parser->params.commands[i] != NULL)
	{
		if (!(parser->params.cmdtmp[i] = (char *)malloc(sizeof(char)
			* (ft_strlen(parser->params.commands[i]) + 1))))
			ft_endparser(parser, 1);
		ft_strlcpy(parser->params.cmdtmp[i], parser->params.commands[i],
			(ft_strlen(parser->params.commands[i]) + 1));
		i++;
	}
}
