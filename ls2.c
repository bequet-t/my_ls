/*
** ls2.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Fri Mar  4 15:33:09 2016 BEQUET Theo
** Last update Fri Mar  4 15:33:10 2016 BEQUET Theo
*/

#include "header.h"

int 			execFonc(char *dir_name, t_ls_option *option, t_file *file)
{
	file = (*option->getFunc)(dir_name, file);
	if (file == NULL)
		return (1);
	file = (*option->sortFunc)(dir_name, file);
	(*option->affFunc)(dir_name, file);
	freeListe(file);
	return (0);
}

void			freeListe(t_file *file)
{
	t_file *tmp;

	while (file != NULL)
	{
		tmp = file->next;
		free(file);
		file = tmp;
	}
}