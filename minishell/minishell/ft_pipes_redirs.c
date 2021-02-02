/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:36:01 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 14:12:24 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exec_pipes_redirs(char *str, char ***envp, t_parser *parser)
{
	ft_pipes_redirs_init(parser);
	if (((ft_strchr(str, '>') || ft_strchr(str, '<')) && ft_strchr(parser->
	params.flagsr, '0')) || ((ft_strchr(str, '|')
	&& ft_strchr(parser->params.flagsp, '0'))))
	{
		parser->pipes.strings = ft_pipes_and_redirs(str, parser);
		if ((ft_pipes(parser, envp)) == 1)
			return (1);
		if (parser->index_for_redirects != 0)
			parser->index_for_redirects--;
		parser->pipes.before = NULL;
		parser->pipes.is_smth = ft_smth(parser->pipes.strings[parser->pipes.k]);
		if (parser->params.index_redir_buf != 0)
			parser->params.index_redir_buf -= 1;
		if ((ft_redirs(parser)) == 1)
			return (1);
		ft_redir_do_func(parser, envp);
		parser->pipes.i = 0;
		free(parser->pipes.before);
		ft_free_double_mass(parser->pipes.strings);
		dup2(parser->pipes.tmp_fd, 0);
		dup2(parser->pipes.tmp_fd1, 1);
		return (1);
	}
	return (0);
}

int		ft_pipes(t_parser *parser, char ***envp)
{
	while (parser->pipes.strings[parser->pipes.k + 1] != NULL)
	{
		if (parser->params.index_redir_buf != 0)
			parser->params.index_redir_buf -= 1;
		parser->pipes.is_smth = ft_smth(parser->pipes.strings[parser->pipes.k]);
		parser->pipes.before = NULL;
		if (parser->pipes.is_smth == 1)
		{
			if ((ft_pipes2(parser, envp)) == 1)
				return (1);
		}
		if (parser->pipes.pid != 0)
		{
			ft_pipes4(parser);
			dup2(parser->pipes.fds[0], 0);
			close(parser->pipes.fds[1]);
			close(parser->pipes.fds[0]);
			ft_get_val(parser);
			free(parser->pipes.before);
		}
		parser->pipes.k++;
	}
	return (0);
}
