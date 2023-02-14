/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:11 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/13 15:23:49 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//struct
typedef struct s_var
{
	char	*buffer;
	char	*next_line;
    int     rd;
	size_t	pos;
}			t_var;

//prototype
void		ft_bzero(void *b, size_t len);
void		*ft_sfree(void *str);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
size_t		ft_find(char *str);

#endif