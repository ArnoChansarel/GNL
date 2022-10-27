/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:36:15 by achansar          #+#    #+#             */
/*   Updated: 2022/10/21 15:01:14 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char    *ft_strdup_nl(const char *s1);
size_t  ft_strlen_nl(const char *s);
size_t  ft_strlen(const char *s);
int	ft_isin(char *str, int c);
char    *ft_strjoin(char const *s1, char const *s2);

#endif