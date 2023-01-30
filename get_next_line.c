/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:03 by oboucher          #+#    #+#             */
/*   Updated: 2023/01/30 16:40:24 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t ft_find(char *str)
{
    size_t i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (i);
}

char *get_next_line(int fd)
{
    static char *str;
    
    if (!str)
        str = ft_calloc(BUFFER_SIZE, sizeof(char));
    if (read(fd, str, BUFFER_SIZE) != 0)
    {
        printf("str");
    }
    return (NULL);
}
