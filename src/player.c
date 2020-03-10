/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** player
*/

#include "matchstick.h"

int good_line(char *command, char **board)
{
    int len = 0;

    for (int i = 0; command[i]; i += 1) {
        if ((command[i] < '0' || command[i] > '9') && command[i] != '-') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        }
    }
    for (; board[len]; len += 1);
    len -= 2;
    if (my_getnbr(command) > len || my_getnbr(command) <= 0) {
        my_printf("Error: this line is out of range\n");
        return (0);
    }
    return (1);
}

int get_nb(char **board, int line)
{
    int nb = 0;

    for (int i = 0; board[line][i]; i += 1)
        if (board[line][i] == '|')
            nb += 1;
    return (nb);
}

int good_matches(char *command, int max_matches, int line, char **board)
{
    int matches = my_getnbr(command);
    int nb = get_nb(board, line);

    for (int i = 0; command[i]; i += 1)
        if (command[i] < '0' || command[i] > '9') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        }
    if (matches > max_matches)
        return (print_error(max_matches));
    if (matches <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (0);
    }
    if (matches > nb) {
        my_printf("Error: not enough matches on this line\n");
        return (0);
    }
    return (1);
}

int player_turn(char **board, int max_matches, char *command, int line)
{
    int matches = 0;

    while (1) {
        my_printf("Line: ");
        if (!(command = get_next_line(0)))
            break;
        if (!good_line(command, board))
            continue;
        line = my_getnbr(command);
        my_printf("Matches: ");
        if (!(command = get_next_line(0)))
            break;
        if (good_matches(command, max_matches, line, board))
            matches = my_getnbr(command);
        else
            continue;
        board = delete_matches(board, line, matches);
        return (1);
    }
    return (0);
}