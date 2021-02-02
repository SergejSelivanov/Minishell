/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lets_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:46:58 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 18:54:02 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_symb(t_parser *parser, char **envp)
{
	static int i = 0;

	if (parser->params.flag_create2 == 2)
	{
		i = 0;
		parser->params.flag_create2 = 1;
	}
	while (parser->crtline[i] != '\0')
	{
		ft_fill_command(parser, ft_call_commands(parser, i, envp), &i, envp);
		if (parser->flagvih == 1)
		{
			ft_free_double_mass(parser->mass_for_names);
			free(parser->params.starmass);
			parser->params.starmass = NULL;
			free(parser->params.flagsr);
			parser->params.flagsr = NULL;
			free(parser->params.flagsp);
			parser->params.flagsp = NULL;
			return (0);
		}
		return (1);
	}
	return (0);
}

void	ft_create_tmp(t_parser *parser)
{
	ft_fill_tmp(parser);
	ft_replace_tmp(parser);
}

void	ft_recalloc_commands(t_parser *parser)
{
	ft_create_tmp(parser);
	ft_free_commands(parser);
	ft_create_mass(parser);
	ft_replace_mass(parser);
	ft_free_tmp(parser);
}

int		ft_start_parse(t_parser *parser, char **envp)
{
	ft_recalloc_commands(parser);
	return (ft_check_symb(parser, envp));
}

int		ft_lets_parse(t_parser *parser, char **envp)
{
	if (parser->params.flag_create == 0)
	{
		ft_init_params(parser);
		ft_create_mass(parser);
		parser->params.flag_create = 1;
		parser->params.flag_create2 = 2;
	}
	return (ft_start_parse(parser, envp));
}
