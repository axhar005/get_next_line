/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/02 15:29:24 by oboucher         ###   ########.fr       */
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
			return (i);
		i++;
	}
	return (0);
}
char *ft_small_split(char *buffer, size_t pos)
{
	char	*fline;
	char	*fnew;

	fline = ft_calloc(pos + 1, sizeof(char));
	if (!fline)
		return (ft_sfree(fline));
	while (pos--)
		fline[pos] = buffer[pos];
	return (fline);
}

char	*get_next_line(int fd)
{
	char		*line;
	char 		*temp;
	static char	*new;
	size_t 		new_line_pos;
	
	new_line_pos = 0;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (ft_sfree(line));
    if (!new)
    {
	    new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    if (!new)
		    return (ft_sfree(new));
    }
	else
	{
		new_line_pos = ft_find(new);
		if (new_line_pos != 0)
		{
			line = ft_small_split(new, new_line_pos);
			temp = new;
			new = ft_strjoin(NULL, &new[new_line_pos+1]);
			return (ft_sfree(temp), line);
		}
		else
		{
			if (new[0] == '\n')
			{
				line[0] = '\n';
				line[1] = '\0';
				return (line);
			}
			line = ft_strjoin(line, new);
			new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    	if (!new)
		    	return (ft_sfree(new));
		}
	}
	while (read(fd, new, BUFFER_SIZE) != 0)
	{
		new_line_pos = ft_find(new);
		if (new_line_pos == 0)
		{
			if  (new[new_line_pos] == '\n')
			{
				line = ft_strjoin(line, "\n\0");
				return (line);
			}
			else
			{
				line = ft_strjoin(line, new);
			}
		}
		else
		{
			line = ft_small_split(new, new_line_pos);
			temp = new;
			new = ft_strjoin(NULL, &new[new_line_pos+1]);
			return (ft_sfree(temp), line);
		}
	}
	
	return (line);
}