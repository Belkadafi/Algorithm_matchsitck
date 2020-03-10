/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** board_management
*/

#include "matchstick.h"

char **delete_matches(char **board, int line, int matches)
{
    int nb = 0;

    my_printf("Player removed %d match(es) from line %d\n", matches, line);
    for (int i = my_strlen(board[line]) - 1; nb < matches; i -= 1) {
        if (board[line][i] == '|') {
            nb += 1;
            board[line][i] = ' ';
        }
    }
    return (board);
}