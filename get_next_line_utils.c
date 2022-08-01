/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:46:07 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/18 14:10:39 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *p)
{
	int	b;

	b = 0;
	if (!p)
		return (0);
	while (p[b])
		b++;
	return (b);
}

char	*search_end(const char *s)
{
	size_t	g;

	g = 0;
	if (!s)
		return (0);
	while (s[g] != '\n')
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		y;
	int		m;
	char	*t;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t)
		return (0);
	m = 0;
	y = 0;
	while (s1[m])
		t[y++] = s1[m++];
	m = 0;
	while (s2[m])
		t[y++] = s2[m++];
	t[y] = '\0';
	free(s1);
	return (t);
}
