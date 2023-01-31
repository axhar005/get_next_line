/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/01/31 17:06:17 by oboucher         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*str;
	static char	*new;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (ft_sfree(str));
    if (!new)
    {
	    new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	    if (!new)
		    return (ft_sfree(new));
    }
    else
    {
        if (ft_find(new) > 0)
            str = ft_strjoin(str, new + ft_find(new) + 1);
    }
    while (read(fd, new, BUFFER_SIZE) != 0)
	{
        if (ft_find(new) == 0)
            str = ft_strjoin(str, new);
        else
        {
            str = ft_strjoin(str, new);
            break;
        } 
	}
	return (str);
}
