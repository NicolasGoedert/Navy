/*
** verif_end.c for verif end of game in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Feb  6 16:46:52 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:15:32 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	parsing_end(char *map, int i, int j)
{
  int	fd;
  char	*buff;
  char	**tab;
  int	a;

  a = 0;
  fd = open(map, O_RDONLY);
  buff = malloc(sizeof(char) * 32000);
  read(fd, buff, 32000);
  tab = str_wordtab(buff);
  while (tab[i])
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == 'x')
	    a = a + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (a);
}

int	verif_end(char *map)
{
  int	count_int;

  count_int = parsing_end(map, 0, 0);
  if (count_int == 14)
    return (0);
  else
    return (1);
}
