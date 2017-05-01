/*
** complete_map1.c for complete map 1 in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy/reste
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Wed Feb  1 13:28:45 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:43:41 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

char	*recup3(char *buff)
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

char    **boat3(char **tab, int k, int i, int j)
{
  char  *buff;
  char  **positions;

  buff = recup3(buff);
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

void	change_map3(char **tab)
{
  int	i;
  int	j;
  int	fd;

  fd = open("map_3", O_WRONLY);
  i = 0;
  while (tab[i])
    {
      write(fd, tab[i], my_strlen(tab[i]));
      if (i + 1 != 10)
	write(fd, "\n", 1);
      i = i + 1;
    }
}

char	**complete_map3(char **tab, int i)
{
  int	fd;
  char	*buff;

  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return (NULL);
  fd = open("map_3", O_RDONLY);
  read(fd, buff, 32000);
  tab = str_wordtab(buff);
  if (i == 0)
    tab = boat3(tab, 0, 0, 0);
  change_map3(tab);
  my_putstr("my positions:\n");
  printab(tab);
}
