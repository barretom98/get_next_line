/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matbarre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:14:41 by matbarre          #+#    #+#             */
/*   Updated: 2023/12/05 16:00:47 by matbarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_save(int fd, char *strstat)
{
	int		read_bytes;
	char	*aux;
	char	*copy;

	read_bytes = 1;
	aux = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (NULL);
	while (!strstat || (!(ft_strchr(strstat, '\n')) && read_bytes > 0))
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(aux);
			free(strstat);
			return (NULL);
		}
		aux[read_bytes] = '\0';
		copy = strstat;
		strstat = ft_strjoin_gnl(strstat, aux);
		free(copy);
	}
	free (aux);
	return (strstat);
}

char	*ft_strprint(char **s)
{
	char	*retstr;
	char	*aux;
	int		i;

	i = 0;
	aux = *s;
	while (*s && (*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s) && (*s)[i] == '\n')
		i++;
	retstr = ft_substr(*s, 0, i);
	*s = ft_substr(*s, i, ft_strlen_gnl(*s));
	if (!*s)
	{
		free(*s);
		return (NULL);
	}
	free(aux);
	if (!retstr[0])
	{
		free(retstr);
		retstr = NULL;
	}
	return (retstr);
}

char	*get_next_line(int fd)
{
	static char	*strstat;
	char		*result;

	if (fd < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE < 0)
		return (NULL);
	strstat = ft_read_save(fd, strstat);
	if (!strstat || !strstat[0])
	{
		free (strstat);
		strstat = NULL;
		return (NULL);
	}
	result = ft_strprint(&strstat);
	return (result);
}
/*
int	main (void)
{
 	char	*test = "Test.txt";
 	char	*line;
 	int		file;

 	file = open(test, O_RDONLY);
 	line = get_next_line(file);
 	printf("%s", line);
 	free (line);
 	return (0);
}
*/
