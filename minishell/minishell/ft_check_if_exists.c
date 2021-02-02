/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_exists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:58:13 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 12:29:15 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_if_exists(t_parser *parser, char **envp)
{
	ft_check_if_exists6(parser);
	if ((ft_check_if_exists1(parser)) == 1)
		return (1);
	if (ft_find_path(envp))
	{
		ft_check_if_exists2(parser, envp);
		ft_check_if_exists3(parser);
		while (parser->ifex.path[parser->ifex.i])
		{
			parser->ifex.buf =
			ft_strjoin(parser->ifex.path[parser->ifex.i], "/");
			parser->ifex.path_append =
			ft_strjoin(parser->ifex.buf, parser->params.starmass);
			if ((parser->ifex.fd =
			(open(parser->ifex.path_append, O_RDONLY))) > -1)
			{
				ft_check_if_exists4(parser);
				return (1);
			}
			ft_check_if_exists5(parser);
		}
		ft_free_double_mass(parser->ifex.path);
	}
	return (0);
}

int		ft_check_if_exists1(t_parser *parser)
{
	if ((ft_check_if_our_func(parser->params.starmass, "echo")) ||
	(ft_check_if_our_func(parser->params.starmass, "cd"))
	|| (ft_check_if_our_func(parser->params.starmass, "pwd"))
	|| (ft_check_if_our_func(parser->params.starmass, "exit"))
	|| (ft_check_if_our_func(parser->params.starmass, "export"))
	|| (ft_check_if_our_func(parser->params.starmass, "unset"))
	|| (ft_check_if_our_func(parser->params.starmass, "env")))
		return (1);
	return (0);
}

void	ft_check_if_exists2(t_parser *parser, char **envp)
{
	while (envp[parser->ifex.i] &&
	(ft_strncmp(envp[parser->ifex.i], "PATH=", 5)))
		parser->ifex.i++;
	parser->ifex.buf = ft_strdup(envp[parser->ifex.i] + 5);
	parser->ifex.i = 0;
	while (parser->ifex.buf[parser->ifex.i])
	{
		if (parser->ifex.buf[parser->ifex.i] == ':')
			parser->ifex.counter++;
		parser->ifex.i++;
	}
	parser->ifex.counter += 1;
	parser->ifex.path =
	(char **)malloc(sizeof(char *) * parser->ifex.counter + 1);
	while (parser->ifex.counter--)
		parser->ifex.path[parser->ifex.counter] = (char *)malloc(1000);
	parser->ifex.counter = 0;
}

void	ft_check_if_exists3(t_parser *parser)
{
	while (parser->ifex.buf[parser->ifex.j])
	{
		if (parser->ifex.buf[parser->ifex.j] == ':')
		{
			ft_strlcpy(parser->ifex.path[parser->ifex.counter],
			parser->ifex.buf, parser->ifex.j + 1);
			parser->ifex.buf2 =
			ft_strdup(parser->ifex.buf + parser->ifex.j + 1);
			free(parser->ifex.buf);
			parser->ifex.buf = ft_strdup(parser->ifex.buf2);
			free(parser->ifex.buf2);
			parser->ifex.j = 0;
			parser->ifex.counter++;
			continue;
		}
		parser->ifex.j++;
		if (!(parser->ifex.buf[parser->ifex.j]))
			ft_strlcpy(parser->ifex.path[parser->ifex.counter],
			parser->ifex.buf, parser->ifex.j + 1);
	}
	parser->ifex.path[parser->ifex.counter + 1] = NULL;
	parser->ifex.i = 0;
	parser->ifex.counter = 0;
	free(parser->ifex.buf);
}

void	ft_check_if_exists4(t_parser *parser)
{
	close(parser->ifex.fd);
	free(parser->ifex.buf);
	free(parser->ifex.path_append);
	ft_free_double_mass(parser->ifex.path);
}
