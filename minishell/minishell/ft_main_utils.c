/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:40 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 18:54:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_write_mess(t_parser *parser)
{
	write(1, "minishell: ", 11);
	write(1, parser->params.starmass, ft_strlen(parser->params.starmass));
	write(1, ": command not found\n", 20);
	parser->dollar = 127;
}

void	ft_shlvl_and_inits(t_parser *parser, t_func *func, char ***envp)
{
	ft_make_free_str(parser);
	ft_init_main(parser, func);
	ft_make_oldpwd_nothing(*envp);
	ft_if_shlvl(*envp, func);
	if (func->is_there_sh == 1)
		ft_change_shlvl(envp, func, parser);
	else
		ft_make_shlvl(envp, parser);
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, ft_sigquit);
}

void	ft_start_of_cycle(t_parser *parser)
{
	ft_prompt_and_oth(parser);
	if (!(parser->start.line[0]) && parser->start.gnl_val == 0)
	{
		write(1, "exit\n", 5);
		ft_free_double_mass(parser->params.string_to_free);
		exit(0);
	}
	parser->crtline = ft_strdup(parser->start.line);
	free(parser->start.line);
	ft_check_token(parser);
}

void	ft_check_argc(char **argv, int argc)
{
	g_sig.pid = 100;
	if (argc > 1)
	{
		write(1, "minishell: ", 11);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, ": No such file or directory\n", 28);
		exit(127);
	}
}

void	ft_some_frees(t_parser *parser, char ***envp)
{
	parser->start.ret = 0;
	g_sig.flag = 0;
	ft_choose_func(parser, envp);
	parser->start.j++;
	ft_free_double_mass(parser->mass_for_names);
	free(parser->params.starmass);
	parser->params.starmass = NULL;
	free(parser->params.flagsr);
	parser->params.flagsr = NULL;
	free(parser->params.flagsp);
	parser->params.flagsp = NULL;
}
