/*
** flag_h.c for flag_h in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 12:29:05 2017 DORIAN DEBOUT
** Last update Sun Feb 19 13:36:40 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	flag_h()
{
  int	first_player_pid;

  first_player_pid = getpid();
  my_putstr("USAGE\n\t   ./navy [");
  my_putnbr(first_player_pid);
  my_putstr("] navy_positions\n\n");
  my_putstr("DESCRIPTION\n\t   ");
  my_putnbr(first_player_pid);
  my_putstr("\t\t    only for the 2nd player. ");
  my_putnbr(first_player_pid);
  my_putstr(",\n\t   navy_positions");
  my_putstr("   file representing the positions of the ships.\n");
}
