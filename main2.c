/*
** main.c for main in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 12:09:42 2017 DORIAN DEBOUT
** Last update Sat Feb 18 14:02:14 2017 DORIAN DEBOUT
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./gnl/gnl.h"

char	*cut(char *s)
{
  int	i;
  int	j;
  int	k;
  char	*s2;

  i = 0;
  k = 0;
  j = my_strlen(s);
  s2 = malloc(sizeof(char) * (j + 1));
  while (s[i] && (s[i] == ' ' || s[i] == '\t'))
    i = i + 1;
  while (j > 2 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\0'))
    j = j - 1;
  j = j + 1;
  while (i < j)
    {
      s2[k] = s[i];
      i = i + 1;
      k = k + 1;
    }
  s2[k + 1] = '\0';
  return (s2);
}

void	save_attack(char *s)
{
  int	fd;

  fd = open("attack_j1", O_WRONLY);
  s = cut(s);
  write(fd, s, my_strlen(s));
}

int	check_command(char *s, char **tab, char **tab2)
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
      save_attack(s);
      check_hit(s, tab, 0, 0);
    }
  return (0);
}

char	**ennemy(char **tab)
{
  int	fd;
  int	fd2;
  char	*buff;
  char	*buff2;

  fd = open("attack_j2", O_RDONLY);
  if ((buff = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  read(fd, buff, 4);
  if ((buff2 = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd2 = open("map_1", O_RDONLY);
  read(fd2, buff2, 32000);
  tab = str_wordtab(buff2);
  tab = actu_map1(tab, buff, 0, 0);
  return (tab);
}

int		main2(int ac, char **av)
{
  char		*s;
  char		**tab;
  char		**tab2;

  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
    flag_h();
  else
    {
      if (check_pos(av) == 84)
	return (84);
      argument(av);
      begin();
      while (verif_end("map_4") != 0 && verif_end("map_3") != 0)
	{
	  my_putstr("attack: ");
	  s = get_next_line(0);
	  while (check_command(s, tab, tab2) == 1)
	    s = get_next_line(0);
	}
      check_winner(verif_end("map_3"), verif_end("map_4"));
    }
  return (0);
}
