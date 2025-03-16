/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:24:48 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/11 20:50:49 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_strjoin1(char *s1, char *s2);
int		ft_strchr1(char *s, int c);
size_t	ft_strlen1(char *s);
char	*ft_read_file(int fd, char *result);
char	*ft_line_line(char *ch);
char	*ft_next_line(char *str);
char	*get_next_line(int fd);
char	*ft_strdup1(char *str);
char	*ft_free_null(char *s1, char *s2);

#endif