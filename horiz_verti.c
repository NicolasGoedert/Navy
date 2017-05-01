/*
** horiz_verti.c for horiz verti in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy/reste
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  1 15:51:38 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:11:34 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**vertical(char **tab, char **positions, int k)
{
  int	j;
  int	i;

  j = 0;
  while (tab[0][j] && positions[k][2] != tab[0][j])
    j = j + 1;
  if (positions[k][3] - positions[k][6] > 0)
    {
      i = positions[k][3] - 48;
      while (i > positions[k][6] - 48)
	{
	  tab[i][j] = positions[k][0];
	  i = i - 1;
	}
    }
  else
    {
      i = positions[k][6] - 48;
      while (i > positions[k][3] - 48)
	{
	  tab[i][j] = positions[k][0];
	  i = i - 1;
	}
    }
  return (tab);
}

char	**horizontal(char **tab, char **positions, int k)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] && positions[k][3] != tab[i][0])
    i = i + 1;
  if (positions[k][2] - positions[k][5] > 0)
    {
      j = positions[k][2] - 48;
      while (j > positions[k][5] - 48)
	{
	  tab[i][j] = positions[k][0];
	  j = j - 2;
	}
    }
  else
    {
      j = (positions[k][5] - 65) * 2 + 2;
      while (j > ((positions[k][2] - 65) * 2 + 2))
	{
	  tab[i][j] = positions[k][0];
	  j = j - 2;
	}
    }
  return (tab);
}
