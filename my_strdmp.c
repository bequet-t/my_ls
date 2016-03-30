/*
** my_strdup.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Thu Mar  3 17:32:12 2016 BEQUET Theo
** Last update Thu Mar  3 17:32:13 2016 BEQUET Theo
*/

#include "header.h"

char *my_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
    {
    	dest[i] = src[i];
    	i = i + 1;
    }
	dest[i] = '\0';
	return (dest);
}

char *my_strdup(char *str)
{
	char *tab;

	tab = malloc(sizeof(char) * (my_strlen(str) + 1));
	tab = my_strcpy(tab, str);
	return (tab);
}