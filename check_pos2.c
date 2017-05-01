/*
** check_pos.c for check pos in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  2 16:11:45 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:34:33 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_point(char **tab)
{
  int	i;
  int	j;
  int	a;

  a = 0;
  i = 0;
  while (tab[i] && i != 4)
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] == ':')
	    a = a + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (a != 8)
    return (84);
}

char	**change_pos_send(char **tab, char *s)
{
  int	fd;
  int	i;
  int	j;

  fd = open(s, O_WRONLY);
  i = 0;
  while (tab[i] && i != 4)
    {
      j = 0;
      while (tab[i][j])
	{
	  if (tab[i][j] >= 'a' && tab[i][j] <= 'z')
	    tab[i][j] = tab[i][j] - 32;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (tab);
}

int	check_pos5(char *av)
{
  int	fd;
  char	*buff;
  char	**tab;

  if ((fd = open(av, O_RDONLY)) == -1)
    return (84);
  if ((buff = malloc(sizeof(char) * 3200)) == NULL)
    return (84);
  if (read(fd, buff, 32000) == -1)
    return (84);
  if (my_strlen(buff) != 32)
    return (84);
  tab = str_wordtab(buff);
  if (!(tab[0][0] >= '1' && tab[0][0] <= '5')
      && !(tab[1][0] >= '1' && tab[1][0] <= '5')
      && !(tab[2][0] >= '1' && tab[2][0] <= '5')
      && !(tab[3][0] >= '1' && tab[3][0] <= '5'))
    return (84);
  if (check_point(tab) == 84)
    return (84);
  tab = change_pos_send(tab, av);
  if (check_same(tab) == 84)
    return (84);
  check_inverse(tab, av);
}

int	check_pos3(char **av)
{
  if (check_pos5(av[2]) == 84 || check_position(av[2], 0) == 84)
    {
      my_putstr("Bad positions or file not found\n");
      return (84);
    }
}
