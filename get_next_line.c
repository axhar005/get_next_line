/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/01 14:03:34 by oboucher         ###   ########.fr       */
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
	size_t i;
	
	i = pos;
	fline = ft_calloc((BUFFER_SIZE - i) + 1, sizeof(char));
	if (!fline)
		return (ft_sfree(fline));
	while (i-- >= 0)
		fline[i] = buffer[i];
	buffer = ft_strjoin(NULL, &buffer[i+1]);
	return (fline);
}

char	*get_next_line(int fd)
{
	char		*line;
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
			line = ft_small_split(new, );
			return (line);
		}
		else
		{
			if (new[0] == '\n')
				return (&c);
			line = ft_strjoin(line, new);
			new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    	if (!new)
		    	return (ft_sfree(new));
		}
	}
	while (read(fd, new, BUFFER_SIZE))
	{
		/* code */
	}
	
	return (line);
}