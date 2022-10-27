/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:59 by achansar          #+#    #+#             */
/*   Updated: 2022/10/27 13:26:15 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
//#define BUFFER_SIZE 10

int	ft_isin(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char *ft_split_gnl(char* full)
{
	int		i;
	int		j;
	char	*left;

	i = 0;
	while(full[i] != '\n' && full[i])
		i++;
	left = malloc(sizeof(char) * (ft_strlen(full + i) + 1));
	if (!left)
		return (NULL);
	j = 0;
	i++;
	while(full[i])
		left[j++] = full[i++];
	left[j] = '\0';
	return (left);
}

char *get_next_line(int fd)
{
	int ret;
	char buff[BUFFER_SIZE + 1];
	static char *rtr;
	char *line;

	ret = 1;
	if (!rtr)
		rtr = "";
	while(ft_isin(buff, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		rtr = ft_strjoin(rtr, buff);
	}
	line = ft_strdup_nl(rtr);
	if(ret != 0)
		rtr = ft_split_gnl(rtr);
	return (line);
}

int main(void)
{
	char *ret;

	int fd = open("textfile.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	ret = get_next_line(fd);
	printf(" END = %s\n", ret);
	ret = get_next_line(fd);
	printf(" END = %s\n", ret);
	ret = get_next_line(fd);
	printf(" END = %s\n", ret);
	ret = get_next_line(fd);
	printf(" END = %s\n", ret);
	ret = get_next_line(fd);
	printf(" END = %s\n", ret);
	
	if (close(fd) == -1)
	{
		return (1);
	}
	free(ret);
	return (0);
}