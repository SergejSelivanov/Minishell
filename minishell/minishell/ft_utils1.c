/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:31:08 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 19:24:00 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi(const char *str)
{
	int		j;
	long	numb;
	int		sgn;

	if (!str)
		return (0);
	j = 0;
	numb = 0;
	sgn = 1;
	while (str[j] == '\v' || str[j] == '\t' || str[j] == '\n'
	|| str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	if (str[j] == '-' || str[j] == '+')
		if (str[j++] == '-')
			sgn = -1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		if (numb > (numb * 10 + (str[j] - '0')))
			return (sgn > 0 ? -1 : 0);
		numb = (numb * 10) + (str[j++] - '0');
	}
	return ((int)(numb * sgn));
}

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 65 && a <= 90) || (a >= 97 && a <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	else
		return (0);
	return (0);
}

int	ft_isnum(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' ||
		c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

int	ft_if_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isnum(str[i])))
			return (0);
		i++;
	}
	return (1);
}
