/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:27:57 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 13:33:41 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd3(t_parser *parser, char ***envp)
{
	if (ft_find_oldpwd(*envp, 1) != -1)
	{
		write(1, (*envp)[ft_find_oldpwd(*envp, 1)] + 7,
		ft_strlen((*envp)[ft_find_oldpwd(*envp, 1)] + 7));
		write(1, "\n", 1);
		if ((chdir((*envp)[ft_find_oldpwd(*envp, 1)] + 7)) == -1)
		{
			write(1, "minishell: cd: ", 15);
			write(1, (*envp)[ft_find_oldpwd(*envp, 1)] + 7,
			ft_strlen((*envp)[ft_find_oldpwd(*envp, 1)] + 7));
			write(1, ": ", 2);
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
			parser->dollar = 1;
		}
	}
	else
	{
		parser->cd.flag_olpwd = 1;
		write(1, "minishell: cd: OLDPWD not set\n", 30);
		parser->dollar = 1;
	}
}

void	ft_cd4(t_parser *parser)
{
	parser->cd.i = ft_strlen(parser->cd.act_path);
	while (parser->cd.act_path[parser->cd.i] != '/')
	{
		parser->cd.act_path[parser->cd.i] = '\0';
		parser->cd.i--;
	}
	if ((chdir(parser->cd.act_path)) == -1)
	{
		write(1, "minishell: cd: ", 15);
		write(1, parser->cd.act_path, ft_strlen(parser->cd.act_path));
		write(1, ": ", 2);
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
		parser->dollar = 1;
	}
}

void	ft_cd5(t_parser *parser, char *str)
{
	parser->cd.str_buf2 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[parser->cd.i] && str[parser->cd.i] != ' ')
	{
		parser->cd.str_buf2[parser->cd.i] = str[parser->cd.i];
		parser->cd.i++;
	}
	parser->cd.str_buf2[parser->cd.i] = '\0';
	if (parser->cd.str_buf2[0] == '/')
		ft_cd5_1(parser);
	else
		ft_cd5_2(parser, str);
}

void	ft_cd5_1(t_parser *parser)
{
	if ((chdir(parser->cd.str_buf2)) == -1)
	{
		write(1, "minishell: cd: ", 15);
		write(1, parser->cd.str_buf2, ft_strlen(parser->cd.str_buf2));
		write(1, ": ", 2);
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
		parser->dollar = 1;
	}
}

void	ft_cd5_2(t_parser *parser, char *str)
{
	parser->cd.str_buf = ft_strjoin("/", parser->cd.str_buf2);
	free(parser->cd.str_buf2);
	parser->cd.str_buf2 = ft_strdup(parser->cd.str_buf);
	free(parser->cd.str_buf);
	parser->cd.append_str =
	ft_strjoin(parser->cd.act_path, parser->cd.str_buf2);
	free(parser->cd.str_buf2);
	if ((chdir(parser->cd.append_str) == -1))
	{
		write(1, "minishell: cd: ", 15);
		write(1, str, ft_strlen(str));
		write(1, ": ", 2);
		write(1, strerror(errno), ft_strlen(strerror(errno)));
		write(1, "\n", 1);
		parser->dollar = 1;
	}
	free(parser->cd.append_str);
}
