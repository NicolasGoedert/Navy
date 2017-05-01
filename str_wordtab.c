/*
** str_wordtab.c for wordtab in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Tue Jan 31 14:01:27 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:23:57 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	nbr_word(char *str)
{
  int	a;
  int	n;

  n = 0;
  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] == '\n')
	{
	  while (str[a] != '\0' && str[a] == '\n')
	    a = a + 1;
	  n = n + 1;
	}
      a = a + 1;
    }
  if (str[a - 1] != '\n')
    n = n + 1;
  return (n);
}

int	nbr_char(char *str, int count)
{
  int	a;
  int	n;

  n = 0;
  a = count;
  while (str[a] != '\0' && (!(str[a] == '\n')))
    {
      a = a + 1;
      n = n + 1;
    }
  return (n);
}

void	word(int c, int *a, char *str, char **tab)
{
  int	b;
  int	ver;

  ver = nbr_char(str, *a);
  if ((tab[c] = malloc(ver + 1)) == NULL)
    return ;
  b = 0;
  while (b < ver)
    {
      tab[c][b] = str[*a];
      b = b + 1;
      (*a) = (*a) + 1;
    }
  tab[c][b] = '\0';
  while (str[*a] != '\0' && ((str[*a] == '\n')))
    (*a)++;
}

char	**wordtab(char *str, int hor)
{
  char	**tab;
  int	b;
  int	a;

  if ((tab = malloc(sizeof(char **) * (hor + 1))) == NULL)
    return (NULL);
  a = 0;
  b = 0;
  while (b < hor)
    {
      word(b, &a, str, tab);
      b = b + 1;
    }
  tab[b] = '\0';
  return (tab);
}

char	**str_wordtab(char *str)
{
  char	**tab;
  int	hor;
  int	i;

  hor = nbr_word(str);
  tab = wordtab(str, hor);
  return (tab);
}
