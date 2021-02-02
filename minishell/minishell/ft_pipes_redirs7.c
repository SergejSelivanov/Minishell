/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:58:52 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 14:14:11 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirs9(t_parser *parser)
{
	write(parser->pipes.tmp_fd1, "minishell: ", 11);
	write(parser->pipes.tmp_fd1, parser->mass_for_names[parser->
	index_for_redirects],
	ft_strlen(parser->mass_for_names[parser->index_for_redirects]));
	write(parser->pipes.tmp_fd1, ": ", 2);
	write(parser->pipes.tmp_fd1, strerror(errno),
	ft_strlen(strerror(errno)));
}

void	ft_redir_do_func(t_parser *parser, char ***envp)
{
	if (parser->pipes.is_smth == 1)
	{
		parser->pipes.pid = fork();
		ft_get_val(parser);
		if (parser->pipes.pid == 0)
		{
			if (parser->pipes.before == NULL)
			{
				parser->pipes.buf =
				ft_strdup(parser->pipes.strings[parser->pipes.k]);
				ft_free_double_mass(parser->pipes.strings);
				if ((ft_check_if_builtin(&(parser->pipes.buf), envp,
				parser, parser->pipes.tmp_fd1)) == 127)
					parser->dollar = 127;
			}
			else
			{
				ft_free_double_mass(parser->pipes.strings);
				if ((ft_check_if_builtin(&(parser->pipes.before), envp,
				parser, parser->pipes.tmp_fd1)) == 127)
					parser->dollar = 127;
			}
			exit(parser->dollar);
		}
	}
}

void	ft_pipes_redirs_init(t_parser *parser)
{
	parser->pipes.is_smth = 0;
	parser->pipes.j = 0;
	parser->pipes.i = 0;
	parser->pipes.k = 0;
	parser->pipes.flag = 0;
	parser->pipes.before = NULL;
	parser->pipes.tmp_fd = dup(0);
	parser->pipes.tmp_fd1 = dup(1);
	parser->params.index_redir = 0;
	parser->params.index_redir_buf = 0;
	parser->index_for_redirects = 0;
}
