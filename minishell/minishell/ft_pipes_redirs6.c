/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:50:52 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 14:01:59 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirs5(t_parser *parser)
{
	ft_redirs4(parser);
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
		else
		{
			parser->params.index_redir++;
			break ;
		}
	}
}

int		ft_redirs6(t_parser *parser)
{
	parser->pipes.fd = open(parser->mass_for_names
	[parser->index_for_redirects], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (parser->pipes.fd == -1)
	{
		ft_redirs9(parser);
		write(parser->pipes.tmp_fd1, "\n", 1);
		if (parser->pipes.pid == 0)
		{
			ft_free_double_mass(parser->pipes.strings);
			free(parser->pipes.before);
			exit(errno);
		}
		parser->dollar = 1;
		dup2(parser->pipes.tmp_fd, 0);
		dup2(parser->pipes.tmp_fd1, 1);
		free(parser->pipes.before);
		ft_free_double_mass(parser->pipes.strings);
		return (1);
	}
	return (0);
}

int		ft_redirs7(t_parser *parser)
{
	parser->pipes.fd = open(parser->mass_for_names[parser->
	index_for_redirects], O_APPEND | O_WRONLY | O_CREAT, S_IRWXU);
	if (parser->pipes.fd == -1)
	{
		ft_redirs9(parser);
		write(parser->pipes.tmp_fd1, "\n", 1);
		if (parser->pipes.pid == 0)
		{
			ft_free_double_mass(parser->pipes.strings);
			free(parser->pipes.before);
			exit(errno);
		}
		parser->dollar = 1;
		dup2(parser->pipes.tmp_fd, 0);
		dup2(parser->pipes.tmp_fd1, 1);
		ft_free_double_mass(parser->pipes.strings);
		free(parser->pipes.before);
		return (1);
	}
	return (0);
}

int		ft_redirs8(t_parser *parser)
{
	parser->pipes.fd = open(parser->mass_for_names[parser->
	index_for_redirects], O_RDONLY, S_IRWXU);
	if (parser->pipes.fd == -1)
	{
		ft_redirs9(parser);
		write(parser->pipes.tmp_fd1, "\n", 1);
		if (parser->pipes.pid == 0)
		{
			ft_free_double_mass(parser->pipes.strings);
			free(parser->pipes.before);
			exit(errno);
		}
		parser->dollar = 1;
		dup2(parser->pipes.tmp_fd, 0);
		dup2(parser->pipes.tmp_fd1, 1);
		ft_free_double_mass(parser->pipes.strings);
		free(parser->pipes.before);
		return (1);
	}
	dup2(parser->pipes.fd, 0);
	return (0);
}

int		ft_redirs_fin(t_parser *parser)
{
	if (parser->pipes.symb == '>')
	{
		if (parser->pipes.flag == 0)
		{
			if ((ft_redirs6(parser)) == 1)
				return (1);
		}
		else
		{
			if ((ft_redirs7(parser)) == 1)
				return (1);
		}
		dup2(parser->pipes.fd, 1);
	}
	else if (parser->pipes.symb == '<')
	{
		if ((ft_redirs8(parser)) == 1)
			return (1);
	}
	return (0);
}
