/*
** check_position.c for position pos in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  8 17:26:20 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:28:27 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_position(char *av, int i)
{
  int	fd;
  char	*buff;
  char	**tab;

  buff = malloc(sizeof(char) * 32000);
  fd = open(av, O_RDONLY);
  read(fd, buff, 32000);
  tab = str_wordtab(buff);
  while (tab[i] && i != 4)
    {
      if (tab[i][2] == tab[i][5])
	{
	  if ((tab[i][6] - tab[i][3] + 49) != tab[i][0])
	    return (84);
	}
      else if (tab[i][3] == tab[i][6])
	{
	  if ((tab[i][5] - tab[i][2] + 49) != tab[i][0])
	    return (84);
	}
      else
	return (84);
      i = i + 1;
    }
}
