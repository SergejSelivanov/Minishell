/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:16:31 by festermo          #+#    #+#             */
/*   Updated: 2020/12/21 14:41:25 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*a;
	int		j;

	if (!src)
		return (NULL);
	j = 0;
	i = 0;
	while (src[i])
		i++;
	a = (char*)malloc(i + 1);
	if (a == NULL)
		return (NULL);
	while (src[j])
	{
		a[j] = src[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_strcpy(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (*(s2 + i) != 0)
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (s1);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	if (!s)
		return ;
	str = s;
	while (n > 0 && str)
	{
		*str = '\0';
		str++;
		n--;
	}
}

char	*ft_strchr(const char *str, int ch)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[j] != '\0')
		j++;
	if (ch == '\0')
		return ((char *)str + j);
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t num, size_t size)
{
	void *arr;

	arr = malloc(num * (size + 1));
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, num * (size + 1));
	return (arr);
}
