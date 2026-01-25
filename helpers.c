/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redline <redline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:09 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/25 13:04:41 by redline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub_s;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_s = (char *)malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1_len + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
int ft_atoi(char *s)
{
	long int i;
	long sign;
	long res;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + (s[i] - 48);
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
			ft_errors();
		i++;
	}
	return (res * sign);
}

char *ft_addspace(char *s1, char *s2)
{
    char    *tmp;
    char    *result;

    if (!s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    tmp = ft_strjoin(s1, " ");
    if (!tmp)
        return (free(s1), NULL);
    result = ft_strjoin(tmp, s2);
    free(s1);
    free(tmp);
    return (result);
}

