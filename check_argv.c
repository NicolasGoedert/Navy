/*
** check_argv.c for check_argv in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Feb  7 09:15:02 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:05:06 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_argv(char **av)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * (my_strlen(av[1]) + 1))) == NULL)
    return (84);
  fd = open("pid_j1", O_RDONLY);
  read(fd, buff, my_strlen(av[1]) + 1);
  if (my_strcmp(buff, av[1]) != 0)
    return (84);
}
