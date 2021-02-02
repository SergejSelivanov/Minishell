/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:55:13 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 14:02:38 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exec(char **envp, char *str, t_parser *parser)
{
	char	*path_append;
	char	*prog_name;
	int		len;
	int		fd;

	parser->dollar = 0;
	len = 0;
	if (!(ft_strncmp("./", str, 2)) && *(str + 5) != ' ')
	{
		path_append = ft_exec3(&str, &len, &prog_name);
		fd = open(prog_name, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			ft_exec2(parser, envp, &prog_name, &path_append);
		}
		else
			ft_exec1(parser, prog_name);
		free(prog_name);
		free(path_append);
		return (1);
	}
	return (0);
}

void	ft_exec1(t_parser *parser, char *prog_name)
{
	write(parser->tmp_fd1, "minishell: ./", 13);
	write(parser->tmp_fd1, prog_name, ft_strlen(prog_name));
	write(parser->tmp_fd1, ": ", 2);
	write(parser->tmp_fd1, strerror(errno), ft_strlen(strerror(errno)));
	write(parser->tmp_fd1, "\n", 1);
	parser->dollar = 126;
	if (errno == 2)
		parser->dollar = 127;
}

void	ft_exec2(t_parser *parser, char **envp,
		char **prog_name, char **path_append)
{
	pid_t pid;

	pid = fork();
	if (pid != 0)
		ft_get_val(parser);
	if (pid == 0)
	{
		free((*prog_name));
		execve((*path_append), NULL, envp);
		free((*path_append));
		exit(0);
	}
}

char	*ft_exec3(char **str, int *len, char **prog_name)
{
	char path[PATH_MAX + 1];
	char *str_buf;
	char *path_append;

	getcwd(path, PATH_MAX + 1);
	(*str) += 2;
	if (ft_strchr(*str, ' '))
		while (!(ft_strchr(" ", (*str)[(*len)])))
			(*len) += 1;
	else
		(*len) = ft_strlen((*str));
	(*prog_name) = (char *)malloc(sizeof(char) * (*len));
	ft_strlcpy((*prog_name), (*str), (*len) + 1);
	str_buf = ft_strjoin(path, "/");
	path_append = ft_strjoin(str_buf, (*prog_name));
	free(str_buf);
	return (path_append);
}
