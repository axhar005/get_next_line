/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/03 14:34:17 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t	ft_find(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *ft_small_split(char *line, size_t *pos)
{
	char	*fnext_line;
	size_t 	i;
	
	i = 0;
	while (line[i])
		if (line[i++] == '\n')
			break ;
	*pos = i;
	fnext_line = ft_calloc(i + 2, sizeof(char));
	if (!fnext_line)
		return (ft_sfree(fnext_line));
	while (i--)
		fnext_line[i] = line[i];
	return (fnext_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	static char	*line;
	int			x;
	size_t 		pos;
	
	
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (ft_sfree(buffer));
	next_line = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (ft_sfree(next_line));
    if (!line)
    {
	    line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    if (!line)
		    return (ft_sfree(line));
	}
	pos = 0;
	while (ft_find(line) == 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		x = read(fd, buffer, BUFFER_SIZE);
			if (x <= 0)
				break;
		line = ft_strjoin(line, buffer);
	}
	next_line = ft_strjoin(next_line, ft_small_split(line, &pos));
	line = ft_strjoin(line + pos, NULL);
	return (next_line);
}