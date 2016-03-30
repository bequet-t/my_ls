/*
** my_strcmp.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Thu Mar  3 09:03:56 2016 BEQUET Theo
** Last update Thu Mar  3 09:03:56 2016 BEQUET Theo
*/

#include "header.h"

int 	my_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
    {
    	i++;
    }
	return (str1[i] - str2[i]);
}

void  	my_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		my_putchar(str[i]);
		i++;
	}
}