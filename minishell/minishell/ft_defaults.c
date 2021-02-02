/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defaults.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:24:32 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 11:53:50 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_defaults(char *str, char **envp, int flag, t_parser *parser)
{
	ft_defaults10(parser);
	if (ft_find_path(envp))
	{
		ft_defaults11(parser, str, envp);
		while (parser->def.path[parser->def.i] &&
		parser->def.path[parser->def.i] != NULL)
		{
			ft_defaults12(parser);
			if ((parser->def.fd =
			(open(parser->def.path_append, O_RDONLY))) > -1)
			{
				ft_defaults13(parser, envp, flag);
				return (1);
			}
			ft_defaults7(parser);
		}
		ft_defaults8(parser);
		return (0);
	}
	ft_defaults9(parser, str);
	return (1);
}

void	ft_defaults1(t_parser *parser, char **envp)
{
	while (envp[parser->def.i] && (ft_strncmp(envp[parser->def.i], "PATH=", 5)))
		parser->def.i++;
	parser->def.buf = ft_strdup(envp[parser->def.i] + 5);
	parser->def.i = 0;
	while (parser->def.buf[parser->def.i])
	{
		if (parser->def.buf[parser->def.i] == ':')
			parser->def.counter++;
		parser->def.i++;
	}
	parser->def.counter += 1;
	if (!(parser->def.path = (char **)malloc(sizeof(char *) *
	(parser->def.counter + 1))))
		exit(0);
	while (parser->def.counter--)
	{
		if (!(parser->def.path[parser->def.counter] =
		(char *)malloc(ft_strlen(parser->def.buf))))
			exit(0);
	}
	parser->def.counter = 0;
}

void	ft_defaults2(t_parser *parser)
{
	while (parser->def.buf[parser->def.j])
	{
		if (parser->def.buf[parser->def.j] == ':')
		{
			ft_strlcpy(parser->def.path[parser->def.counter],
			parser->def.buf, parser->def.j + 1);
			parser->def.buf2 = ft_strdup(parser->def.buf + parser->def.j + 1);
			free(parser->def.buf);
			parser->def.buf = ft_strdup(parser->def.buf2);
			free(parser->def.buf2);
			parser->def.j = 0;
			parser->def.counter++;
			continue;
		}
		parser->def.j++;
		if (!(parser->def.buf[parser->def.j]))
			ft_strlcpy(parser->def.path[parser->def.counter],
			parser->def.buf, parser->def.j + 1);
	}
	parser->def.path[parser->def.counter + 1] = NULL;
	parser->def.i = 0;
	parser->def.counter = 0;
}

void	ft_defaults3(t_parser *parser, char *str)
{
	parser->def.argv = ft_split(str, ' ');
	parser->def.buf2 = ft_strdup(parser->def.argv[0]);
	free(parser->def.argv[0]);
	parser->def.argv[0] = ft_strjoin("./", parser->def.buf2);
	parser->def.i = 0;
	free(parser->def.buf);
}

void	ft_defaults4(t_parser *parser, char **envp)
{
	parser->def.pid = fork();
	g_sig.pid = parser->def.pid;
	if (parser->def.pid != 0)
		ft_get_val(parser);
	if (parser->def.pid == 0)
	{
		free(parser->def.buf);
		free(parser->def.buf2);
		ft_free_double_mass(parser->def.path);
		execve(parser->def.path_append, parser->def.argv, envp);
	}
}
