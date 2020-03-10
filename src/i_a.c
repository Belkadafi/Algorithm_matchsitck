/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** i_a
*/

#include "matchstick.h"

int print_error(int max_matches)
{
    my_printf("Error: "
    "you cannot remove more than %d matches per turn\n", max_matches);
    return (0);
}

void print_board(char **tab)
{
    for (int i = 0; tab[i]; i += 1)
        my_printf("%s\n", tab[i]);
}

char **i_a_turn(char **board)
{
    for (int i = 0; board[i]; i += 1) {
        for (int j = my_strlen(board[i]) - 1; j > 0; j -= 1)
            if (board[i][j] == '|') {
                board[i][j] = ' ';
                my_printf("\nAI's turn...\nAI remo"
                "ved 1 match(es) from line %d\n", i);
                print_board(board);
                return (board);
            }
    }
    return (board);
}