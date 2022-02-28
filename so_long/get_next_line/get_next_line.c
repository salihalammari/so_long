/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:28:14 by slammari          #+#    #+#             */
/*   Updated: 2022/02/27 19:29:22 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_line(char *rest)
{
	char	*line;
	int		index;
	int		i;

	if (ft_strlen(rest) <= 0)
		return (NULL);
	index = find_new_line(rest);
	if (index == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = (char *)malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_rest(char *rest)
{
	int		len;
	int		index;
	char	*tmp;

	if (!rest)
		return (NULL);
	len = ft_strlen(rest);
	index = find_new_line(rest);
	if (index != -1)
	{
		tmp = ft_substr(rest, (index + 1), (len - index - 1));
		free(rest);
		rest = tmp;
		return (rest);
	}
	free(rest);
	return (NULL);
}

char	*ft_read_line(int fd, char *buff, char *rest)
{
	char	*tmp;
	int		n;

	n = 0;
	while (find_new_line(rest) == -1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(rest, buff);
			if (rest)
				free(rest);
			rest = tmp;
		}
		else
			break ;
	}
	free(buff);
	if (n == -1)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rest = ft_read_line(fd, buff, rest);
	line = ft_line(rest);
	rest = ft_rest(rest);
	return (line);
}
