/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 12:41:53 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 13:30:46 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(char *str, char ***envp, t_parser *parser)
{
	ft_cd_init(parser);
	if (!(ft_strncmp("cd", str, 2)) && (*(str + 2) == ' ' || !(*(str + 2))))
	{
		parser->cd.act_buf = ft_strdup(parser->cd.act_path);
		str += 2;
		while (ft_strchr(" ", *str) && (*(str + 1)))
			str++;
		if (*str == ' ' || *str == '\0')
		{
			if ((ft_cd2(parser, envp)) == 1)
				return (1);
		}
		else if (*str == '-' && ((*(str + 1) == ' ') || !(*(str + 1))))
			ft_cd3(parser, envp);
		else if (!(ft_strncmp("..", str, 2)) &&
		(*(str + 2) == ' ' || !(*(str + 2))))
			ft_cd4(parser);
		else
			ft_cd5(parser, str);
		ft_cd_end(parser, envp);
		return (1);
	}
	return (0);
}

void	ft_cd_init(t_parser *parser)
{
	parser->cd.i = 0;
	parser->cd.flag_olpwd = 0;
	parser->cd.flag = 0;
	getcwd(parser->cd.act_path, PATH_MAX + 1);
	parser->dollar = 0;
}

void	ft_cd_end(t_parser *parser, char ***envp)
{
	if (parser->cd.flag_olpwd == 0)
	{
		if (ft_find_oldpwd(*envp, 2) != -1)
			ft_change_oldpwd(envp, ft_find_oldpwd(*envp, 2), parser);
		else
			ft_put_oldpwd_to_end(envp, parser->cd.act_buf, parser);
	}
	getcwd(parser->cd.act_path, PATH_MAX + 1);
	ft_change_pwd(envp, parser->cd.act_path, parser);
	free(parser->cd.act_buf);
}

int		ft_cd2(t_parser *parser, char ***envp)
{
	while ((*envp)[parser->cd.i] != NULL)
	{
		if (!(ft_strncmp((*envp)[parser->cd.i], "HOME=", 5)))
		{
			parser->cd.flag = 1;
			break ;
		}
		parser->cd.i++;
	}
	if (parser->cd.flag == 0)
	{
		write(1, "minishell: cd: HOME not set\n", 28);
		parser->dollar = 1;
		return (1);
	}
	parser->cd.str_buf = (*envp)[parser->cd.i] + 5;
	if ((chdir(parser->cd.str_buf)) == -1)
		ft_cd2_part_2(parser);
	return (0);
}

void	ft_cd2_part_2(t_parser *parser)
{
	write(1, "minishell: cd: ", 15);
	write(1, parser->cd.str_buf, ft_strlen(parser->cd.str_buf));
	write(1, ": ", 2);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	parser->dollar = 1;
}
