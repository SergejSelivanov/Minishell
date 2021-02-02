/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defaults2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:51:18 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 11:55:07 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_defaults5(t_parser *parser, char **envp)
{
	ft_free_double_mass(parser->def.path);
	free(parser->def.buf2);
	free(parser->def.buf);
	execve(parser->def.path_append, parser->def.argv, envp);
}

void	ft_defaults6(t_parser *parser)
{
	free(parser->def.buf2);
	ft_free_double_mass(parser->def.argv);
	free(parser->def.buf);
	ft_free_double_mass(parser->def.path);
	free(parser->def.path_append);
}

void	ft_defaults7(t_parser *parser)
{
	free(parser->def.path_append);
	free(parser->def.buf);
	parser->def.i++;
}

void	ft_defaults8(t_parser *parser)
{
	free(parser->def.buf2);
	ft_free_double_mass(parser->def.path);
	ft_free_double_mass(parser->def.argv);
}

void	ft_defaults9(t_parser *parser, char *str)
{
	write(1, "minishell: ", 11);
	write(1, str, ft_strlen(str));
	write(1, ": No such file or directory\n", 28);
	parser->dollar = 127;
}
