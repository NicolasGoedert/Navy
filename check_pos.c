/*
** check_pos.c for check pos in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  2 16:11:45 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:47:09 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	check_pos1(char **av)
{
  int	fd;
  char	*buff;
  char	**tab;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
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
  tab = change_pos_send(tab, av[1]);
  if (check_same(tab) == 84)
    return (84);
  check_inverse(tab, av[1]);
}

void	new_pos(int fd, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] && i != 3)
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i + 1 != 4)
	write(fd, "\n", 1);
      i = i + 1;
    }
}

int	check_pos(char **av)
{
  if (check_pos1(av) == 84 || check_position(av[1], 0) == 84)
    {
      my_putstr("Bad positions or file not found\n");
      return (84);
    }
}
