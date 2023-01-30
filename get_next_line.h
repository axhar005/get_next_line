/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/01/30 13:20:22 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFUER_SIZE
#  define BUFFUER_SIZE = 42
# endif

#include <unistd.h>

//prototype
void	bzero(void *b, size_t len);
void    *ft_sfree(void *str);
void	*ft_calloc(size_t count, size_t size);
size_t  ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif