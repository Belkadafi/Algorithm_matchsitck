/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include "matchstick.h"

int i_a_loose(void)
{
    my_printf("I lost... snif... but I'll get you next time!\n");
    return (1);
}

int i_a_win(void)
{
    my_printf("You lost, too bad...\n");
    return (2);
}

int is_game(char **board)
{
    for (int i = 0; board[i]; i += 1)
        for (int j = 0; board[i][j]; j += 1)
            if (board[i][j] == '|')
                return (1);
    return (0);
}

int game_loop(char **board, int max_matches)
{
    char *command = NULL;

    while (1) {
        my_printf("\nYour turn:\n");
        if (!is_game(board))
            return (i_a_loose());
        if (player_turn(board, max_matches, command, 0)) {
            print_board(board);
            if (!is_game(board))
                return (i_a_win());
            board = i_a_turn(board);
        } else
            return (0);
    }
}

int main(int ac, char **av)
{
    char **board = NULL;

    if (ac != 3)
        return (84);
    if (!(my_str_isnum(av[1])) || !(my_str_isnum(av[2])))
        return (84);
    board = get_board(my_getnbr(av[1]));
    return (game_loop(board, my_getnbr(av[2])));
}