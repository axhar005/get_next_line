/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:52 by oboucher          #+#    #+#             */
/*   Updated: 2023/02/02 15:26:08 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    printf("|1|%s", get_next_line(fd));
    printf("|2|%s", get_next_line(fd));
    close(fd);
}