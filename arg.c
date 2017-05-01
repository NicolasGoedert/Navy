/*
** arg.c for arg in /home/nicolas94200/PSU/PSU_2016_navy
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Wed Feb 15 16:18:49 2017 goedert nicolas
** Last update Fri Feb 17 14:35:00 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	argument(char **av)
{
  int	fd;

  fd = open("arg1", O_WRONLY);
  write(fd, av[1], my_strlen(av[1]));
}

void	argument2(char **av)
{
  int	fd;

  fd = open("arg2", O_WRONLY);
  write(fd, av[2], my_strlen(av[2]));
}
