/*
** check_hit.c for check hit in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  2 13:36:47 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:05:26 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	**map4_empty(char **tab2)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return NULL;
  fd = open("map_4", O_RDONLY);
  read(fd, buff, 32000);
  tab2 = str_wordtab(buff);
  return (tab2);
}

void	my_modif_map4(char **tab)
{
  int	fd;
  int	i;

  i = 0;
  fd = open("map_4", O_WRONLY);
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	write(fd, "\n", 1);
      i = i + 1;
    }
}

char	**check_hit2(char *s, char **tab, int j, int i)
{
  char	**tab2;
  char	**tab3;

  tab2 = complete_map4(tab2);
  tab3 = map4_empty(tab3);
  while (tab2[0] && s[0] != tab2[0][j])
    j = j + 1;
  while (tab2[i] && s[1] != tab2[i][0])
    i = i + 1;
  if (tab2[i][j] != '.')
    {
      hit_miss1(s, 0);
      tab3[i][j] = 'x';
    }
  else
    {
      hit_miss1(s, 1);
      tab3[i][j] = 'o';
    }
  tab = complete_map3(tab, 1);
  my_putstr("enemy's positions:\n");
  my_modif_map4(tab3);
  printab(tab3);
}
