/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:26:59 by achansar          #+#    #+#             */
/*   Updated: 2022/11/01 17:50:13 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*char_b;

	char_b = (char *) b;
	if (len < 1)
		return (b);
	i = 0;
	while (i < len)
	{
		char_b[i] = c;
		i++;
	}
	return (b);
}

char	*ft_split_gnl(char *full)
{
	int		i;
	int		j;
	char	*left;

	if (!full)
		return (NULL);
	i = 0;
	left = NULL;
	while (full[i])
	{
		if (full[i++] == '\n')
			break ;
	}
	left = malloc(sizeof(char) * (ft_strlen(full + i) + 1));
	if (!left)
		return (ft_free_all(full, 0));
	j = 0;
	while (full[i])
		left[j++] = full[i++];
	left[j] = '\0';
	free (full);
	return (left);
}

char	*ft_readline(int fd, char *save)
{
	int		byte_read;
	char	*buff;

	byte_read = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		if (!save)
			return (ft_free_all(buff, 0));
		save[0] = '\0';
	}
	ft_memset(buff, '\0', BUFFER_SIZE + 1);
	while (ft_isin(buff, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free_all(buff, save));
		buff[byte_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free (buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_readline(fd, save);
	line = ft_strdup_nl(save);
	save = ft_split_gnl(save);
	if (!save || !line)
		return (ft_free_all(line, save));
	return (line);
}
/*
int main(void)
{
	char *ret;

	int fd = open("textfile.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	ret = get_next_line(fd);
	printf(" END = %s", ret);
	free(ret);
	
	if (close(fd) == -1)
	{
		return (1);
	}
	printf("main ret = %s\n", ret);
	system("leaks a.out");
	return (0);
}*/