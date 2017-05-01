/*
** complete_map2.c for complete map 2 in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Thu Feb  2 12:04:37 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:37:35 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	*recup2(char *buff)
{
  int	fd;
  int	fd2;
  char	*buff2;

  fd2 = open("arg2", O_RDONLY);
  buff2 = malloc(sizeof(char) * 32000);
  read(fd2, buff2, 32000);
  fd = open(buff2, O_RDONLY);
  if ((buff = malloc(sizeof(char) * (32000))) == NULL)
    return (NULL);
  read(fd, buff, 32000);
  return (buff);
}

char	**boat2(char **tab, int k, int i, int j)
{
  char	*buff;
  char	**positions;

  buff = recup2(buff);
  positions = str_wordtab(buff);
  while (positions[k] && k != 4)
    {
      i = 0;
      j = 0;
      while (tab[0][i] && positions[k][2] != tab[0][i])
	i = i + 1;
      while (tab[j][0] && positions[k][3] != tab[j][0])
	j = j + 1;
      tab[j][i] = positions[k][0];
      i = 0;
      j = 0;
      while (tab[0][i] && positions[k][5] != tab[0][i])
	i = i + 1;
      while (tab[j][0] && positions[k][6] != tab[j][0])
	j = j + 1;
      tab[j][i] = positions[k][0];
      k = k + 1;
    }
  tab = complete_enter(tab, positions, 0);
  return (tab);
}

char	**map2_print(char **tab2)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd = open("map_2", O_RDONLY);
  read(fd, buff, 32000);
  tab2 = str_wordtab(buff);
  my_putstr("enemy's positions:\n");
  printab(tab2);
}

char	**complete_map2(char **tab)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd = open("map_2", O_RDONLY);
  read(fd, buff, 32000);
  tab = str_wordtab(buff);
  tab = boat2(tab, 0, 0, 0);
  return (tab);
}
