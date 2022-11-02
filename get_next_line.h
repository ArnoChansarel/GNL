/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:36:15 by achansar          #+#    #+#             */
/*   Updated: 2022/11/02 16:01:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup_nl(char *s1);
int		ft_strlen(char *s);
int		ft_isin(char *str, int c);
int		ft_isin(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_free_all(char *s1, char **s2);

#endif
