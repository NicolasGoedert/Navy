/*
** check_hit.c for check hit in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  2 13:36:47 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:05:49 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**map2_empty(char **tab2)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd = open("map_2", O_RDONLY);
  read(fd, buff, 32000);
  tab2 = str_wordtab(buff);
  return (tab2);
}

void	my_modif_map(char **tab)
{
  int	fd;
  int	i;

  i = 0;
  fd = open("map_2", O_WRONLY);
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	write(fd, "\n", 1);
      i = i + 1;
    }
  printab(tab);
}

void	hit_miss1(char *s, int i)
{
  if (i == 0)
    {
      my_putstr(s);
      my_putstr(": hit\n\n");
    }
  else
    {
      my_putstr(s);
      my_putstr(": missed\n\n");
    }
}

char	**check_hit(char *s, char **tab, int j, int i)
{
  char	**tab2;
  char	**tab3;

  tab2 = complete_map2(tab2);
  tab3 = map2_empty(tab3);
  while (tab2[0] && s[0] != tab2[0][j])
    j = j + 1;
  while (tab2[i] && s[1] != tab2[i][0])
    i = i + 1;
  if (tab2[i][j] >= '2' && tab2[i][j] <= '8')
    {
      hit_miss1(s, 0);
      tab3[i][j] = 'x';
    }
  else
    {
      hit_miss1(s, 1);
      tab3[i][j] = 'o';
    }
  tab = waiting(tab);
  tab = complete_map1(tab, 1);
  my_putstr("enemy's positions:\n");
  my_modif_map(tab3);
}
