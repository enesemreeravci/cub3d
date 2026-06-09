/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:53:57 by eeravci           #+#    #+#             */
/*   Updated: 2026/06/09 15:40:35 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	c;
	int		read_bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open map file");
	count = 0;
	while (1)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes < 0)
			error_exit("Cannot read map file");
		if (read_bytes == 0)
			break ;
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

static char	*read_line_fd(int fd)
{
	char	c;
	char	*line;
	int		i;
	int		read_bytes;

	line = malloc(10000);
	if (!line)
		error_exit("malloc failed");
	i = 0;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes < 0)
			error_exit("cannot read map file");
		if (read_bytes == 0 || c == '\n')
			break ;
		line[i++] = c;
	}
	line[i] = '\0';
	if (read_bytes == 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	**read_file(char *filename)
{
	int		fd;
	int		lines_count;
	char	**lines;
	int		i;

	lines_count = count_lines(filename);
	lines = malloc(sizeof(char *) * (lines_count + 1));
	if (!lines)
		error_exit("malloc failed");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("cannot open map file");
	i = 0;
	while (1)
	{
		lines[i] = read_line_fd(fd);
		if (!lines[i])
			break ;
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
