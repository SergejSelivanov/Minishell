/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:43:18 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 13:12:56 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pipes2(t_parser *parser, char ***envp)
{
	pipe(parser->pipes.fds);
	parser->pipes.pid = fork();
	if (parser->pipes.pid == 0)
	{
		dup2(parser->pipes.fds[1], 1);
		close(parser->pipes.fds[0]);
		if ((ft_redirs_in_pipes(parser)) == 1)
			return (1);
		close(parser->pipes.fds[1]);
		parser->dollar = 0;
		if (parser->pipes.before == NULL && parser->pipes.is_smth == 1)
			ft_pipes3(parser, envp);
		else if (parser->pipes.before != NULL && parser->pipes.is_smth == 1)
		{
			ft_free_double_mass(parser->pipes.strings);
			if ((ft_check_if_builtin(&(parser->pipes.before),
			envp, parser, parser->pipes.tmp_fd1)) == 127)
				parser->dollar = 127;
		}
		exit(parser->dollar);
	}
	return (0);
}

void	ft_pipes3(t_parser *parser, char ***envp)
{
	free(parser->pipes.before);
	parser->pipes.buf =
	ft_strdup(parser->pipes.strings[parser->pipes.k]);
	ft_free_double_mass(parser->pipes.strings);
	if ((ft_check_if_builtin(&(parser->pipes.buf),
	envp, parser, parser->pipes.tmp_fd1)) == 127)
		parser->dollar = 127;
}

void	ft_pipes4(t_parser *parser)
{
	while ((ft_strchr(parser->pipes.strings[parser->pipes.k], '>')
	|| ft_strchr(parser->pipes.strings[parser->pipes.k], '<'))
	&& ft_strchr(parser->params.flagsr + parser->params.index_redir_buf, '0'))
	{
		ft_pipes5(parser);
		if ((parser->pipes.strings[parser->pipes.k][parser->pipes.i] == '>' &&
		parser->params.flagsr[parser->params.index_redir] == '0')
		&& parser->pipes.symb == '>')
		{
			parser->pipes.flag = 1;
			parser->pipes.i++;
			parser->params.index_redir++;
		}
		parser->params.index_redir_buf = parser->params.index_redir;
		parser->pipes.buf = ft_strdup(parser->pipes.strings[parser->pipes.k]
		+ parser->pipes.i);
		free(parser->pipes.strings[parser->pipes.k]);
		parser->pipes.strings[parser->pipes.k] = ft_strdup(parser->pipes.buf);
		free(parser->pipes.buf);
		ft_pipes6(parser);
		ft_pipes7(parser);
	}
}

void	ft_pipes5(t_parser *parser)
{
	parser->pipes.flag = 0;
	parser->pipes.i = 0;
	parser->pipes.j = 0;
	parser->params.index_redir = parser->params.index_redir_buf;
	while (parser->pipes.strings[parser->pipes.k][parser->pipes.i])
	{
		while (parser->pipes.strings[parser->pipes.k][parser->pipes.i] != '>'
		&& parser->pipes.strings[parser->pipes.k][parser->pipes.i] != '<'
		&& parser->pipes.strings[parser->pipes.k][parser->pipes.i])
			parser->pipes.i++;
		if (parser->params.flagsr[parser->params.index_redir] == '1')
		{
			parser->pipes.i++;
			parser->params.index_redir += 1;
			continue ;
		}
		else
		{
			parser->params.index_redir += 1;
			break ;
		}
	}
	parser->pipes.symb =
	parser->pipes.strings[parser->pipes.k][parser->pipes.i];
	parser->pipes.i++;
}

void	ft_pipes6(t_parser *parser)
{
	while (ft_strchr(" ", *((parser->pipes.strings)[parser->pipes.k]))
	&& parser->pipes.strings[parser->pipes.k][0])
	{
		parser->pipes.buf =
		ft_strdup(parser->pipes.strings[parser->pipes.k] + 1);
		free(parser->pipes.strings[parser->pipes.k]);
		parser->pipes.strings[parser->pipes.k] = ft_strdup(parser->pipes.buf);
		free(parser->pipes.buf);
	}
}
