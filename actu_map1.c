/*
** actu_map1.c for actu map 1 in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Sun Feb  5 09:54:10 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:03:50 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**actu_map1(char **tab, char *buff, int i, int j)
{
  int	fd;

  fd = open("map_1", O_WRONLY);
  while (tab[0] && tab[0][j] != buff[0])
    j = j + 1;
  while (tab[i] && tab[i][0] != buff[1])
    i = i + 1;
  if (tab[i][j] >= '1' && tab[i][j] <= '9')
    tab[i][j] = 'x';
  else
    tab[i][j] = 'o';
  i = 0;
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	write(fd, "\n", 1);
      i = i + 1;
    }
  return (tab);
}
