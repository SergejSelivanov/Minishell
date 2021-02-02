/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:27:10 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 19:36:41 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigquit(void)
{
	char path[PATH_MAX + 1];

	getcwd(path, PATH_MAX + 1);
	if (g_sig.pid != 0)
	{
		write(1, "Quit: 3\n", 8);
		write(1, path, ft_strlen(path));
		write(1, "$ ", 2);
		g_sig.flag = 1;
		g_sig.pid = 0;
	}
}

void	ft_sigint(void)
{
	char path[PATH_MAX + 1];

	write(1, "\b\b  ", ft_strlen("\b\b  "));
	write(1, "\n", 1);
	getcwd(path, PATH_MAX + 1);
	write(1, path, ft_strlen(path));
	write(1, "$ ", 2);
	if (g_sig.pid != 0)
	{
		g_sig.flag = 1;
		g_sig.pid = 0;
	}
}

void	ft_get_val(t_parser *parser)
{
	int test;

	test = 0;
	wait(&parser->dollar);
	if (WIFEXITED(parser->dollar))
		test = WEXITSTATUS(parser->dollar);
	else if (WIFSIGNALED(parser->dollar))
		test = WTERMSIG(parser->dollar) + 128;
	parser->dollar = test;
}
