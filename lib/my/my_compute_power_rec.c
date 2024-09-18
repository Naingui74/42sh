/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_compute_power_rec.c
*/

int my_compute_power_rec(int nb, int power)
{
    int result = nb;

    if (power < 0) {
        return (0);
    } else if (power == 0) {
        return (1);
    } else {
        return nb * my_compute_power_rec(nb, power - 1);
    }
}
