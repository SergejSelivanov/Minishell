/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:16:06 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 16:37:00 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_widen(char *str, int size)
{
	char *new_str;

	if (!(new_str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}

static void	ft_if_smth_read(char *read_line, char **line_to_eq,
			int **int_arr, char **remain)
{
	int		i;
	char	*src_line;

	i = 0;
	while (read_line[i] != '\0')
	{
		if (read_line[i] == '\n')
			break ;
		if ((*int_arr)[0] >= (*int_arr)[2])
			*line_to_eq = ft_widen(*line_to_eq, ((*int_arr)[2] += BUFFER_SIZE));
		(*line_to_eq)[(*int_arr)[0]] = read_line[i];
		(*int_arr)[0] += 1;
		i++;
	}
	if ((src_line = ft_strchr(read_line, '\n')))
	{
		src_line++;
		*remain = src_line;
	}
}

static int	ft_readnfree(int *int_arr, char **read_line,
			char **line_to_eq, char **remain)
{
	int	ret_val;
	int test;

	test = 0;
	while (1)
	{
		while ((int_arr[1] = read(int_arr[3], *read_line, BUFFER_SIZE)) > 0)
		{
			ft_if_smth_read(*read_line, *&line_to_eq, &int_arr, *&remain);
			if (ft_strchr(*read_line, '\n'))
				break ;
			ft_bzero(*read_line, BUFFER_SIZE);
			test = 1;
		}
		if (int_arr[1] == 0 && test == 1)
			continue;
		else
			break ;
	}
	ret_val = int_arr[1];
	free(int_arr);
	ft_elsefree(ret_val, read_line);
	return (ret_val);
}

static int	ft_rem_handl(char **remain, int **int_arr,
			char **line_to_eq, char **line)
{
	if (*remain)
	{
		if (ft_strchr(*remain, '\n'))
		{
			while ((*remain)[(*int_arr)[0]] != '\n')
			{
				(*line_to_eq)[(*int_arr)[0]] = (*remain)[(*int_arr)[0]];
				(*int_arr)[0] += 1;
			}
			*remain = *remain + (*int_arr)[0] + 1;
			*line = ft_strdup(*line_to_eq);
			free(*line_to_eq);
			return (1);
		}
		else
		{
			while ((*remain)[(*int_arr)[0]] != '\0')
			{
				(*line_to_eq)[(*int_arr)[0]] = (*remain)[(*int_arr)[0]];
				(*int_arr)[0] += 1;
			}
			ft_bzero(*remain, (*int_arr)[0]);
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*remain;
	static char *read_line;
	char		*line_to_eq;
	int			*int_arr;
	int			ret_val;

	if (!read_line)
		read_line = (char *)ft_calloc(1, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 1 || !(line_to_eq = ft_calloc(1, BUFFER_SIZE))
	|| read(fd, read_line, 0) < 0 ||
	!(int_arr = (int *)malloc(sizeof(int) * 4)))
		return (-1);
	int_arr[0] = 0;
	int_arr[2] = BUFFER_SIZE;
	int_arr[3] = fd;
	if (ft_rem_handl(&remain, &int_arr, &line_to_eq, line))
	{
		free(int_arr);
		return (1);
	}
	ft_bzero(read_line, BUFFER_SIZE);
	ret_val = ft_readnfree(int_arr, &read_line, &line_to_eq, &remain);
	*line = ft_strdup(line_to_eq);
	free(line_to_eq);
	return (ret_val == 0 ? 0 : 1);
}
