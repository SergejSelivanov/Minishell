/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:43:58 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 15:55:48 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_tens(int n, int sign)
{
	int		i;

	i = 0;
	if (sign == 0)
	{
		while (n > 9)
		{
			n /= 10;
			i++;
		}
	}
	else
	{
		while (-n > 9)
		{
			n /= 10;
			i++;
		}
	}
	return (i + 1);
}

static int		if_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void		ft_fill_arr(int n, int n1, char *arr, int sign)
{
	int		i;
	int		j;
	int		k;

	k = 1;
	i = 0;
	j = 1;
	while (i < count_tens(n, if_negative(n)))
	{
		while (j < count_tens(n, if_negative(n)))
		{
			n1 /= 10;
			j++;
		}
		n1 %= 10;
		arr[if_negative(n) + i] = n1 + '0';
		n1 = n * sign;
		i++;
		k++;
		j = k;
	}
	arr[if_negative(n) + i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*arr;
	int		n1;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	n1 = n * sign;
	arr = (char *)malloc(sizeof(char) *
			(count_tens(n, if_negative(n)) + if_negative(n) + 1));
	if (arr == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(arr, "-2147483648", 12);
		return (arr);
	}
	if (if_negative(n) == 1)
		arr[0] = '-';
	ft_fill_arr(n, n1, arr, sign);
	return (arr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char*)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		arr[i] = s2[j];
		j++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
