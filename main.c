/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:52 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/08 20:20:27 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    printf("|1|%s", get_next_line(fd));
    printf("|2|%s", get_next_line(fd));
    printf("|3|%s", get_next_line(fd));
    printf("|4|%s", get_next_line(fd));
    printf("|5|%s", get_next_line(fd));
    printf("|6|%s", get_next_line(fd));
    printf("|7|%s", get_next_line(fd));
    printf("|8|%s", get_next_line(fd));
    printf("|9|%s", get_next_line(fd));
    printf("|10|%s", get_next_line(fd));
    printf("|11|%s", get_next_line(fd));
    printf("|12|%s", get_next_line(fd));
    printf("|13|%s", get_next_line(fd));
    printf("|14|%s", get_next_line(fd));
    close(fd);
}