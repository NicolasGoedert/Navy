/*
** game.c for game in /home/DoWdoX/PROJECT/PSU/PSU_2016_navy
** 
** Made by DORIAN DEBOUT
** Login   <DoWdoX@epitech.net>
** 
** Started on  Mon Jan 30 15:14:10 2017 DORIAN DEBOUT
** Last update Fri Feb 17 15:04:23 2017 DORIAN DEBOUT
*/

#include "./include/my.h"

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}

int		my_getnbr(char *str)
{
  long int      integer;
  int		i;
  int		sign;

  sign = 1;
  i = 0;
  integer = 0;
  if (my_strcmp(str, "-2147483648") == 0)
    return (-2147483648);
  while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
	   || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
	 || str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign = sign * - 1;
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      integer = integer * 10 + (str[i] - '0');
      i = i + 1;
    }
  if (integer < -2147483648 || integer > 2147483647)
    return (0);
  return (integer * sign);
}

int	recup_epid()
{
  int	fd;
  char	*buff;
  int	epid;

  fd = open("pid_j1", O_RDONLY);
  if ((buff = malloc(sizeof(char) * 32000)) == NULL)
    return (84);
  read(fd, buff, 32000);
  epid = my_getnbr(buff);
}

void	begin2(char **tab, char **tab2)
{
  int	my_pid;
  int	fd;
  int	epid;
  char	*pid;

  epid = recup_epid();
  my_pid = getpid();
  pid = convert(my_pid);
  my_putstr("my_pid: ");
  my_putnbr(my_pid);
  my_putstr("\nsuccessfully connected\n\n");
  kill(epid, SIGUSR1);
  tab = complete_map3(tab, 0);
  tab2 = map4_print(tab2);
  fd = open("pid_j2", O_WRONLY);
  write(fd, pid, int_len(my_pid) - 1);
}
