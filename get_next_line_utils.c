/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matbarre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:15:02 by matbarre          #+#    #+#             */
/*   Updated: 2023/12/05 17:45:10 by matbarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	c1;

	c1 = c;
	i = 0;
	while (s[i] != c1 && s[i] != '\0')
		i++;
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*subs;
	int		slen;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen_gnl((char *)s);
	if (len > slen - start)
		len = slen - start;
	if (start >= slen)
		return (ft_strdup(""));
	subs = (char *)malloc (sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*copy;

	i = ft_strlen_gnl(s1);
	j = 0;
	copy = malloc(sizeof(char) * i + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[j] && s1)
	{
		copy[j] = (*(char *)&s1[j]);
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
