/*
** my_putchar.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Mon Feb 29 10:39:14 2016 BEQUET Theo
** Last update Mon Feb 29 11:13:02 2016 BEQUET Theo
*/

#include <unistd.h>
#include <stdlib.h>

void  my_putchar(char c)
{
	write(1, &c, 1);
}

void  my_putstr(char *str)
{
  	while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

int my_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char *my_strcat(char *dest, char *src)
{
	int len;
	int i;

	len = my_strlen(dest);
	i = 0;
	while(src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

void	my_put_nbr(int n)
{
  int	res;
  int	d;

  res = 0;
  d = 1;
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  while ((n / d) >= 10)
    d = d * 10;
  while (d > 0)
    {
      res = (n / d) % 10;
      my_putchar(res + 48);
      d = d / 10;
    }
}
