/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:45:56 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/16 15:46:30 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*st_string_go(char *st_string)
{
	int		i;
	int		b;
	char	*st_string2;

	i = 0;
	while (st_string[i] && st_string[i] != '\n')
		i++;
	if (st_string[i] == '\0')
	{
		free (st_string);
		return (0);
	}
	st_string2 = malloc(sizeof(char) * (ft_strlen(st_string) - i + 1));
	if (!st_string2)
		return (0);
	b = 0;
	i++;
	while (st_string[i])
		st_string2[b++] = st_string[i++];
	st_string2[b] = '\0';
	free(st_string);
	return (st_string2);
}

char	*vivod(char *st_string)
{
	int		i;
	char	*string2;

	i = 0;
	if (st_string[i] == '\0')
		return (0);
	while (st_string[i] && st_string[i] != '\n')
		i++;
	string2 = malloc(sizeof(char) * (i + 2));
	if (!string2)
		return (0);
	i = 0;
	while (st_string[i] && st_string[i] != '\n')
	{
		string2[i] = st_string[i];
		i++;
	}
	if (st_string[i] == '\n')
	{
		string2[i] = st_string[i];
		i++;
	}
	string2[i] = '\0';
	return (string2);
}

static char	*sos(int fd, char *string)
{
	char	*buf;
	int		c;

	c = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!search_end(string) && c != 0)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1 )
		{
			free(buf);
			return (NULL);
		}
		buf[c] = '\0';
		string = ft_strjoin(string, buf);
	}
	free(buf);
	return (string);
}

char	*get_next_line(int fd)
{
	char			*string2;
	static char		*st_string[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st_string[fd] = sos(fd, st_string[fd]);
	if (!st_string[fd])
		return (0);
	string2 = vivod(st_string[fd]);
	st_string[fd] = st_string_go (st_string[fd]);
	return (string2);
}
