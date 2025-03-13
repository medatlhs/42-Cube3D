/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:14:38 by achahlao          #+#    #+#             */
/*   Updated: 2025/02/26 10:45:35 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	next = (char *)malloc(((ft_strlen1(str) - i) + 1));
	if (!next)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free(str);
	return (next);
}

char	*ft_line_line(char *ch)
{
	char	*line;
	int		i;

	i = 0;
	if (!ch)
		return (NULL);
	while (ch[i] && ch[i] != '\n')
		i++;
	line = (char *)malloc((size_t)((i + 2) * sizeof(char)));
	if (!line)
		return (NULL);
	i = 0;
	while (ch[i] && ch[i] != '\n')
	{
		line[i] = ch[i];
		i++;
	}
	if (ch[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *result)
{
	char	*buff;
	int		nb_read;

	buff = (char *)malloc((size_t)(sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buff)
		return (NULL);
	nb_read = 1;
	while (nb_read > 0 && !ft_strchr1(result, '\n'))
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
			return (ft_free_null(result, buff));
		buff[nb_read] = '\0';
		result = ft_strjoin1(result, buff);
		if (!result)
		{
			free(buff);
			return (NULL);
		}
	}
	if (nb_read == 0 && result[0] == '\0')
		return (ft_free_null(result, buff));
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stc_v;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stc_v = ft_read_file(fd, stc_v);
	if (!stc_v)
		return (NULL);
	line = ft_line_line(stc_v);
	stc_v = ft_next_line(stc_v);
	return (line);
}
