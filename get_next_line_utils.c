/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:06 by oboucher          #+#    #+#             */
/*   Updated: 2023/01/30 13:16:06 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	bzero(void *b, size_t len)
{
	while (len--)
        ((char *)b)[len] = 0;
}

void *ft_sfree(void *str)
{
    if (str)
        free(str);
    return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = malloc(count * size);
	if (!new)
		return (new = ft_sfree(new));
		bzero(new, count * size);
	return (new);
}

size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        i++;
    }
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (new == NULL)
		return (new = ft_sfree(new));
	while (s1_len + s2_len-- > s1_len)
        new[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
        new[s1_len] = s1[s1_len];
    if (*new == 0)
        new = ft_sfree(new);
    return (ft_sfree(s1), new);
}