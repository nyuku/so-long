/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:41:26 by angela            #+#    #+#             */
/*   Updated: 2023/03/04 16:44:29 by angnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h”

void	ft_read_line(int fd, char **return_line);
char	*ft_sorting_leftover(char **return_line);

char	*get_next_line(int fd)
{
	static char	*return_line;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(return_line);
		return_line = NULL;
		return (NULL);
	}
	ft_read_line(fd, &return_line);
	line = ft_sorting_leftover(&return_line);
	if (!line)
	{	
		free(return_line);
		return_line = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}

void	ft_read_line(int fd, char **return_line)
{
	ssize_t	readed;
	int		check_end;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	check_end = 0;
	if (!*return_line)
		*return_line = ft_strdup("");
	while (!ft_strchr(*return_line, '\n') && check_end == 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		temp = *return_line;
		*return_line = ft_strjoin(*return_line, buffer);
		free(temp);
		if (readed < BUFFER_SIZE)
			check_end = 1;
	}
}

char	*ft_sorting_leftover(char **return_line)
{
	char	*line;
	int		i;
	int		len;
	char	*temp;

	len = ft_strlen(*return_line);
	i = 0;
	while (i < len)
	{
		if (return_line[0][i] == '\n' || return_line[0][i] == '\0')
			break ;
		i++;
	}
	if (return_line[0][i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = ft_substr(*return_line, 0, i);
	temp = *return_line;
	*return_line = ft_substr(*return_line, i, (len - i));
	free(temp);
	return (line);
}
