/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:07 by achansar          #+#    #+#             */
/*   Updated: 2022/10/27 12:38:35 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t  ft_strlen_nl(const char *s)
{
	size_t  l;

	l = 0;
	while (s[l] != '\n' && s[l])
	    l++;
	return (l);
}

size_t  ft_strlen(const char *s)
{
	size_t  l;

	l = 0;
	while (s[l])
	    l++;
	return (l);
}

char    *ft_strdup_nl(const char *s1)
{
	int	i;
	char	*s2;

	i = 0;
	s2 = malloc((ft_strlen_nl(s1) + 1) * sizeof(char));   // => FREE
	if (!s2)
		return (0);
	while (s1[i] != '\n' && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	int     i;
	int     j;
	char    *concat;

	if ((!s1) || (!s2))
		return (0);
	concat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)); // => FREE 2
	if (!concat)
		return (0);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	return (concat);
}