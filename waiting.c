/*
** waiting.c for wait in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  9 14:07:27 2017 DORIAN DEBOUT
** Last update Mon Feb 13 10:34:02 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**waiting(char **tab)
{
  kill(recup_epid2(), SIGUSR2);
  my_putstr("waiting for enemy's attack...");
  pause();
  hand3(0, "map_1");
  tab = ennemy(tab);
}

void	waiting2()
{
  my_putstr("waiting for enemy's attack...");
  pause();
  hand3(1, "map_3");
  my_putstr("attack: ");
}
