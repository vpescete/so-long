/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:46:36 by robegarc          #+#    #+#             */
/*   Updated: 2023/01/27 11:47:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*get_line(int fd, char *line);
char	*ft_strchr(char *s, int c);
char	*get_new_line(char *line);
char	*get_next_line(int fd);
char	*new_line(char *line);
int		ft_strlen(char *s);

#endif
