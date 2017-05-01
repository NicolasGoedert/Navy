/*
** main.c for main in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 12:09:42 2017 DORIAN DEBOUT
** Last update Sat Feb 18 14:02:36 2017 DORIAN DEBOUT
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./gnl/gnl.h"

void	save_attack2(char *s)
{
  int	fd;

  fd = open("attack_j2", O_WRONLY);
  s = cut(s);
  write(fd, s, my_strlen(s));
}

int	check_command2(char *s, char **tab, char **tab2)
{
  int	i;

  i = 0;
  s = cut(s);
  s = check_order(s);
  if (!(s[i] >= 'A' && s[i] <= 'H') || !(s[i + 1] >= '1' && s[i + 1] <= '9'))
    {
      my_putstr("wrong position\n");
      my_putstr("attack: ");
      return (1);
    }
  else
    {
      check_hit2(s, tab, 0, 0);
      save_attack2(s);
    }
  return (0);
}

char	**actu_map3(char **tab, char *buff, int i, int j)
{
  int	fd;

  fd = open("map_3", O_WRONLY);
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

char	**ennemy2(char **tab)
{
  int	fd;
  int	fd2;
  char	*buff;
  char	*buff2;

  fd = open("attack_j1", O_RDONLY);
  if ((buff = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  read(fd, buff, 4);
  if ((buff2 = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd2 = open("map_3", O_RDONLY);
  read(fd2, buff2, 32000);
  tab = str_wordtab(buff2);
  tab = actu_map3(tab, buff, 0, 0);
  return (tab);
}

int	main3(int ac, char **av)
{
  char	*s;
  char	**tab;
  char	**tab2;

  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
    flag_h();
  else
    {
      if (check_pos3(av) == 84)
	return (84);
      argument2(av);
      begin2();
      while (verif_end("map_3") != 0 && verif_end("map_4") != 0)
	{
	  waiting2();
	  s = get_next_line(0);
	  tab = ennemy2(tab);
	  while (check_command2(s, tab, tab2) == 1)
	    s = get_next_line(0);
	  kill(recup_epid(), SIGUSR2);
	}
      check_winner(verif_end("map_4"), verif_end("map_3"));
    }
  return (0);
}
