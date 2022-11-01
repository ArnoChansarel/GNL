/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:07 by achansar          #+#    #+#             */
/*   Updated: 2022/11/01 18:09:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free_all(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_isin(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (0);
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!i)
		return (ft_free_all(s1, 0));
	concat = malloc((i + 1) * sizeof(char));
	if (!concat)
		return (ft_free_all(s1, 0));
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	free (s1);
	return (concat);
}

char	*ft_strdup_nl(char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (ft_free_all(s1, 0));
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		if (s2[i++] == '\n')
			break ;
	}
	s2[i] = '\0';
	return (s2);
}
