/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defaults3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:51:49 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 12:33:15 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_defaults10(t_parser *parser)
{
	parser->def.i = 0;
	parser->def.j = 0;
	parser->def.counter = 0;
}

void	ft_defaults11(t_parser *parser, char *str, char **envp)
{
	ft_defaults1(parser, envp);
	ft_defaults2(parser);
	ft_defaults3(parser, str);
}

void	ft_defaults12(t_parser *parser)
{
	parser->def.buf =
	ft_strjoin(parser->def.path[parser->def.i], "/");
	parser->def.path_append =
	ft_strjoin(parser->def.buf, parser->def.buf2);
}

void	ft_defaults13(t_parser *parser, char **envp, int flag)
{
	close(parser->def.fd);
	if (flag == 0)
		ft_defaults4(parser, envp);
	else
		ft_defaults5(parser, envp);
	ft_defaults6(parser);
}
