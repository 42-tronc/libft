/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:56 by croy              #+#    #+#             */
/*   Updated: 2022/12/20 10:27:06 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_to_stash(char *stash, char *buffer)
{
	char	*dst;

	dst = gnl_str_join(stash, buffer);
	free(stash);
	stash = NULL;
	return (dst);
}

static char	*check_buffer(int fd, char *stash)
{
	char	*buffer;
	int		can_read;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	can_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (can_read)
	{
		can_read = read(fd, buffer, BUFFER_SIZE);
		if (can_read < 0)
			return (free(buffer), NULL);
		buffer[can_read] = '\0';
		stash = add_to_stash(stash, buffer);
		if (!stash || ft_strrchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

static char	*fill_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n' )
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	temp = malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1));
	if (!temp)
		return (free(stash), NULL);
	i++;
	while (stash[i + j])
	{
		temp[j] = stash[i + j];
		j++;
	}
	temp[j] = '\0';
	return (free(stash), temp);
}

/**
 * @brief Get the next line object and return it
 *
 * @param fd file descriptor
 * @return char* line read or NULL if nothing to read or an error occurs
 * (includes the '\n' except if EOS does not end with a '\n')
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) != 0)
		return (free(stash), stash = NULL, NULL);
	stash = check_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = fill_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = clean_stash(stash);
	return (line);
}
