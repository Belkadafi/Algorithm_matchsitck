/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** get_board
*/

#include "matchstick.h"

void my_x_strcat(char *s1, char *s2, int x)
{
    for (int i = 0; i < x; i += 1)
        my_strcat(s1, s2);
}

char **get_board(int len)
{
    int nb = len * 2 + 1;
    int mid = (nb - 1) / 2;
    char *buffer = malloc(sizeof(char) * ((len + 2) * (nb + 1) + 1));

    for (int i = 0; i < (len + 2) * (nb + 1); i += 1)
        buffer[i] = '\0';
    my_x_strcat(buffer, "*", nb);
    my_x_strcat(buffer, "\n", 1);
    for (int count = 1; count < nb; count += 2) {
        my_x_strcat(buffer, "*", 1);
        my_x_strcat(buffer, " ", mid - ((count + 1) / 2));
        my_x_strcat(buffer, "|", count);
        my_x_strcat(buffer, " ", mid - ((count + 1) / 2));
        my_x_strcat(buffer, "*", 1);
        my_x_strcat(buffer, "\n", 1);
    }
    my_x_strcat(buffer, "*", nb);
    my_x_strcat(buffer, "\n", 1);
    my_printf(buffer);
    return (my_str_to_word_array(buffer));
}