/*
** game.c for game in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 15:14:10 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:04:48 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int	int_len(int nb)
{
  int	div;
  int	count;

  div = 1;
  count = 1;
  while (nb / div >= 1)
    {
      div = div * 10;
      count = count + 1;
    }
  return (count);
}

char	*convert(int nb)
{
  int	div;
  char	*pid;
  int	i;

  i = int_len(nb);
  if ((pid = malloc(sizeof(char) * i)) == NULL)
    return (NULL);
  i = i - 1;
  div = 10;
  pid[i] = '\0';
  while (i > 0)
    {
      pid[i - 1] = (nb % div) + 48;
      nb = nb / 10;
      i = i - 1;
    }
  return (pid);
}

void	begin(char **tab, char **tab2)
{
  int	my_pid;
  int	fd;
  char	*pid;

  my_pid = getpid();
  pid = convert(my_pid);
  my_putstr("my_pid: ");
  my_putnbr(my_pid);
  my_putstr("\nwaiting for enemy connexion...\n");
  fd = open("pid_j1", O_WRONLY);
  write(fd, pid, int_len(my_pid) - 1);
  pause();
  tab = complete_map1(tab, 0);
  tab2 = map2_print(tab2);
}
