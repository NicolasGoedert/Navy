/*
** check_superpos.c for check superposition of boat in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  8 17:58:20 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:08:29 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_superpos(char **tab, char *av)
{
  int	i;
  int	j;
  int	a;

  i = 2;
  a = 0;
  tab = complete_map1(tab, 0);
  while (tab[i])
    {
      j = 2;
      while (tab[i][j])
	{
	  if (tab[i][j] >= '2' && tab[i][j] <= '5')
	    a = a + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (a != 14)
    return (84);
  return (0);
}
