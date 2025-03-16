/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:41:48 by achahlao          #+#    #+#             */
/*   Updated: 2025/02/26 10:46:00 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_null(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr1(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (s1 == NULL)
		s1 = ft_strdup1("");
	if (!s2 && !s1)
		return (NULL);
	str = (char *)malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (str == NULL)
		return (ft_free_null(s1, NULL));
	i = 0;
	c = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[c])
		str[i++] = s2[c++];
	str[ft_strlen1(s1) + ft_strlen1(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup1(char *str)
{
	char	*p;
	size_t	m;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	m = ft_strlen1(str);
	p = (char *)malloc(m + 1);
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}
