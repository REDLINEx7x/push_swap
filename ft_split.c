/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamhouc <moamhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:04:03 by moamhouc          #+#    #+#             */
/*   Updated: 2026/01/28 21:37:15 by moamhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		i;
	int		j;
	size_t	strs_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strs_len = ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(strs_len + 1);
	if (!final_str)
		return (NULL);
	while (s1[i])
		final_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final_str[j++] = s2[i++];
	final_str[j] = '\0';
	return (final_str);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**catch_word(char *s, char **splits, char c)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tmp = i;
			while (s[i] && s[i] != c)
				i++;
			splits[j] = ft_substr(s, tmp, i - tmp);
			if (!splits[j])
				return (free_arr(splits), NULL);
			j++;
		}
	}
	splits[j] = NULL;
	return (splits);
}

char	**ft_split(char *s, char c)
{
	int		arr_len;
	char	**splits;

	if (!s)
		return (NULL);
	arr_len = count_words(s, c);
	splits = malloc((arr_len + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	splits = catch_word(s, splits, c);
	return (splits);
}
