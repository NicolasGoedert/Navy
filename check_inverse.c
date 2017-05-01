/*
** check_inverse.c for check_inverse in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  8 16:15:22 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:06:05 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**check_inverse(char **tab, char *av)
{
  int	i;
  char	c;
  int	fd;

  i = 0;
  while (tab[i])
    {
      if (tab[i][2] >= '1' && tab[i][2] <= '8'
	  && tab[i][3] >= 'A' && tab[i][3] <= 'H')
	{
	  c = tab[i][2];
	  tab[i][2] = tab[i][3];
	  tab[i][3] = c;
	}
      if (tab[i][5] >= '1' && tab[i][5] <= '8'
	  && tab[i][6] >= 'A' && tab[i][6] <= 'H')
	{
	  c = tab[i][5];
	  tab[i][5] = tab[i][6];
	  tab[i][6] = c;
	}
      i = i + 1;
    }
  fd = open(av, O_WRONLY);
  new_pos(fd, tab);
}

int	check_same(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][2] >= 'A' && tab[i][2] <= 'H'
	  && tab[i][3] >= 'A' && tab[i][3] <= 'H'
	  || tab[i][5] >= 'A' && tab[i][5] <= 'H'
	  && tab[i][6] >= 'A' && tab[i][6] <= 'H'
	  || tab[i][2] >= '1' && tab[i][2] <= '8'
	  && tab[i][3] >= '1' && tab[i][3] <= '8'
	  || tab[i][5] >= '1' && tab[i][5] <= '8'
	  && tab[i][6] >= '1' && tab[i][6] <= '8')
	return (84);
      i = i + 1;
    }
}
