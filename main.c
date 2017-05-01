/*
** main.c for main in /home/DoWdoX/test
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Fri Feb  3 16:40:14 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:23:25 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

void	hand()
{
  my_putstr("enemy connected\n\n");
}

int	hitmiss(char *buff, char *map)
{
  int	fd;
  char	*buff2;
  char	**tab;
  int	i;
  int	j;

  fd = open(map, O_RDONLY);
  if ((buff2 = malloc(sizeof(char) * 32000)) == NULL)
    return (84);
  read(fd, buff2, 32000);
  tab = str_wordtab(buff2);
  i = 0;
  j = 0;
  while (tab[0] && tab[0][j] != buff[0])
    j = j + 1;
  while (tab[i] && tab[i][0] != buff[1])
    i = i + 1;
  if (tab[i][j] >= '1' && tab[i][j] <= '9')
    return (0);
  else
    return (1);
}

void	hand3(int i, char *map)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return ;
  if (i == 0)
    fd = open("attack_j2", O_RDONLY);
  else
    fd = open("attack_j1", O_RDONLY);
  if (read(fd, buff, 32000) == -1)
    return ;
  my_putstr(buff);
  if (hitmiss(buff, map) == 0)
    my_putstr(": hit\n\n");
  else
    my_putstr(": missed\n\n");
}

void	hand2()
{
  my_putchar('\n');
}

int	main(int ac, char **av)
{
  signal(SIGUSR1, hand);
  signal(SIGUSR2, hand2);
  if (ac == 2)
    {
      if (main2(ac, av) == 84)
	return (84);
    }
  else if (ac == 3)
    {
      if (check_argv(av) == 84)
	return (84);
      if (main3(ac, av) == 84)
	return (84);
    }
  else
    return (84);
  reset_all();
  return (0);
}
