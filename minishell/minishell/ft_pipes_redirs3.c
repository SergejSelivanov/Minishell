/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:29:43 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 15:45:30 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_redirs_in_pipes(t_parser *parser)
{
	while ((ft_strchr(parser->pipes.strings[parser->pipes.k], '>') ||
	ft_strchr(parser->pipes.strings[parser->pipes.k], '<')) &&
	ft_strchr(parser->params.flagsr + parser->params.index_redir_buf, '0'))
	{
		ft_redirs_in_pipes_funcs_call(parser);
		if (parser->pipes.symb == '>')
		{
			if (parser->pipes.flag == 0)
			{
				if ((ft_redirs_in_pipes6(parser)) == 1)
					return (1);
			}
			else
				parser->pipes.fd = open(parser->mass_for_names[parser->
				index_for_redirects], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
			if ((ft_redirs_in_pipes7(parser)) == 1)
				return (1);
		}
		else if (parser->pipes.symb == '<')
			if ((ft_redirs_in_pipes8(parser)) == 1)
				return (1);
		close(parser->pipes.fd);
		parser->index_for_redirects++;
	}
	return (0);
}

void	ft_redirs_in_pipes2(t_parser *parser)
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

void	ft_redirs_in_pipes3(t_parser *parser)
{
	if ((parser->pipes.strings[parser->pipes.k][parser->pipes.i] == '>'
	&& parser->params.flagsr[parser->params.index_redir] == '0')
	&& parser->pipes.symb == '>')
	{
		parser->pipes.flag = 1;
		parser->pipes.i++;
		parser->params.index_redir++;
	}
	parser->params.index_redir_buf = parser->params.index_redir;
	if (parser->pipes.before == NULL)
	{
		parser->pipes.before = (char *)malloc(sizeof(char) *
		(parser->pipes.i - parser->pipes.flag));
		ft_strlcpy(parser->pipes.before, parser->pipes.strings[parser->
		pipes.k], (parser->pipes.i - parser->pipes.flag));
	}
	parser->pipes.buf =
	ft_strdup(parser->pipes.strings[parser->pipes.k] + parser->pipes.i);
	free(parser->pipes.strings[parser->pipes.k]);
	parser->pipes.strings[parser->pipes.k] = ft_strdup(parser->pipes.buf);
	free(parser->pipes.buf);
}

void	ft_redirs_in_pipes4(t_parser *parser)
{
	while (ft_strchr(" ", *((parser->pipes.strings)[parser->pipes.k]))
	&& parser->pipes.strings[parser->pipes.k])
	{
		parser->pipes.buf =
		ft_strdup(parser->pipes.strings[parser->pipes.k] + 1);
		free(parser->pipes.strings[parser->pipes.k]);
		parser->pipes.strings[parser->pipes.k] = ft_strdup(parser->pipes.buf);
		free(parser->pipes.buf);
	}
}

void	ft_redirs_in_pipes5(t_parser *parser)
{
	while (parser->pipes.strings[parser->pipes.k][parser->pipes.j])
	{
		while (parser->pipes.strings[parser->pipes.k][parser->pipes.j]
		&& parser->pipes.strings[parser->pipes.k][parser->pipes.j] != '>'
		&& parser->pipes.strings[parser->pipes.k][parser->pipes.j] != '<'
		&& parser->pipes.strings[parser->pipes.k][parser->pipes.j] != ' ')
			parser->pipes.j++;
		if (parser->pipes.strings[parser->pipes.k][parser->pipes.j] != ' '
		&& parser->params.flagsr[parser->params.index_redir] == '1')
		{
			parser->pipes.j++;
			parser->params.index_redir += 1;
			continue ;
		}
		else if (parser->pipes.strings[parser->pipes.k][parser->pipes.j] == ' ')
			break ;
		else
		{
			parser->params.index_redir++;
			break ;
		}
	}
}
