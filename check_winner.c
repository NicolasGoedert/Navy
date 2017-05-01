/*
** check_winner.c for check the winner in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb  6 19:51:16 2017 DORIAN DEBOUT
** Last update Wed Feb  8 13:01:52 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	check_winner(int i, int j)
{
  if (i == 0)
    my_putstr("Enemy won\n");
  else if (j == 0)
    my_putstr("I won\n");
  else
    my_putstr("Egality\n");
}
