/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:54:18 by festermo          #+#    #+#             */
/*   Updated: 2020/12/28 19:34:59 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig g_sig;

void	ft_choose_func2(t_parser *parser, char ***envp)
{
	if (parser->start.ret == 0)
		parser->start.ret = ft_unset(envp, parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_exit(parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_exec(*envp, parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_defaults(parser->
		params.commands[parser->start.j], *envp, 0, parser);
	if (parser->start.ret == 0)
		ft_not_found(parser->params.commands[parser->start.j], parser, 1);
}

void	ft_choose_func(t_parser *parser, char ***envp)
{
	parser->start.ret = ft_exec_pipes_redirs(parser->
	params.commands[parser->start.j], envp, parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_echo(parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_pwd(parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_cd(parser->
		params.commands[parser->start.j], envp, parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_env(*envp, parser->
		params.commands[parser->start.j], parser);
	if (parser->start.ret == 0)
		parser->start.ret = ft_export(envp, parser->
		params.commands[parser->start.j], parser);
	ft_choose_func2(parser, envp);
}

void	ft_prompt_and_oth(t_parser *parser)
{
	parser->if_synt_error = 0;
	parser->params.flag_create = 0;
	parser->start.j = 0;
	parser->start.ret = 0;
	getcwd(parser->start.path, PATH_MAX + 1);
	if (g_sig.flag == 0)
	{
		write(1, parser->start.path, ft_strlen(parser->start.path));
		write(1, "$ ", 2);
		g_sig.flag = 0;
	}
	g_sig.flag = 0;
	parser->start.gnl_val = get_next_line(1, &(parser->start.line));
}

void	ft_init_main(t_parser *parser, t_func *func)
{
	func->is_there_sh = 0;
	func->shlvl = 0;
	func->index = -1;
	parser->params.index = 0;
	parser->params.index_redir = 0;
	parser->params.index_redir_buf = 0;
	parser->dollar = 0;
	g_sig.pid = 0;
	parser->start.tmp_fd = dup(0);
	parser->start.tmp_fd1 = dup(1);
	parser->tmp_fd1 = parser->start.tmp_fd1;
	parser->start.j = 0;
	parser->params.flag_create2 = 1;
}

int		main(int argc, char **argv, char **envp)
{
	t_parser	parser;
	t_func		func;

	ft_check_argc(argv, argc);
	ft_shlvl_and_inits(&parser, &func, &envp);
	while (1)
	{
		ft_start_of_cycle(&parser);
		if (parser.if_synt_error == 1)
			continue;
		while ((ft_lets_parse(&parser, envp) == 1)
		&& parser.params.commands[parser.start.j] != NULL)
		{
			if (parser.params.starmass && (ft_check_if_exists(&parser, envp))
			== 0 && ft_strchr(parser.params.starmass, ' '))
			{
				ft_write_mess(&parser);
				continue ;
			}
			ft_some_frees(&parser, &envp);
		}
		free(parser.crtline);
		ft_free_commands(&parser);
	}
	return (0);
}
