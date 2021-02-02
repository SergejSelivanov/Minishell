/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_redirs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 15:22:31 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 15:28:54 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_redirs_in_pipes8(t_parser *parser)
{
	parser->pipes.fd = open(parser->mass_for_names
	[parser->index_for_redirects], O_RDONLY, S_IRWXU);
	if (parser->pipes.fd == -1)
	{
		ft_redirs_print_error(parser);
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
	dup2(parser->pipes.fd, 0);
	return (0);
}

void	ft_redirs_print_error(t_parser *parser)
{
	write(parser->pipes.tmp_fd1, "minishell: ", 11);
	write(parser->pipes.tmp_fd1,
	parser->mass_for_names[parser->index_for_redirects],
	ft_strlen(parser->mass_for_names[parser->index_for_redirects]));
	write(parser->pipes.tmp_fd1, ": ", 2);
	write(parser->pipes.tmp_fd1, strerror(errno), ft_strlen(strerror(errno)));
	write(parser->pipes.tmp_fd1, "\n", 1);
}

void	ft_redirs_in_pipes_funcs_call(t_parser *parser)
{
	ft_redirs_in_pipes2(parser);
	ft_redirs_in_pipes3(parser);
	ft_redirs_in_pipes4(parser);
	ft_redirs_in_pipes5(parser);
}

int		ft_redirs_in_pipes6(t_parser *parser)
{
	parser->pipes.fd = open(parser->mass_for_names[parser->index_for_redirects],
	O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (parser->pipes.fd == -1)
	{
		ft_redirs_print_error(parser);
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

int		ft_redirs_in_pipes7(t_parser *parser)
{
	if (parser->pipes.fd == -1)
	{
		ft_redirs_print_error(parser);
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
	dup2(parser->pipes.fd, 1);
	return (0);
}
