#include "push_swap.h"

char	*ft_subs(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sub_s;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_slen(s);
	if (s_len <= start)
		return (ft_sdup(""));
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
size_t	ft_slen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_slen(s1);
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
int atol(char *s)
{
	long int i;
	long sign;
	long res;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] >= 9 && s[i] <= 13 || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
}
