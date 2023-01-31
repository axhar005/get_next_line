/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:15:52 by oboucher          #+#    #+#             */
/*   Updated: 2023/01/31 17:52:02 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    printf("|0|%s\n", get_next_line(fd));
    printf("|0|%s\n", get_next_line(fd));
    close(fd);
}