/*
** sort_fonction.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Thu Mar  3 14:49:18 2016 BEQUET Theo
** Last update Thu Mar  3 14:49:23 2016 BEQUET Theo
*/

#include "header.h"

t_file 				*noSortOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	while (tmp->next != NULL)
	{
		if (my_strcmp(tmp->name, tmp->next->name) >= 1)
		{
			swap(tmp);
			tmp = file_list;
		}
		else
		  tmp = tmp->next;
	}
	my_strcmp(dir_name, "");
	return (file_list);
}

t_file 				*tOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	while (tmp->next != NULL)
	{
		if (tmp->info.st_mtime < tmp->next->info.st_mtime)
		{
			swap(tmp);
			tmp = file_list;
		}
		else
			tmp = tmp->next;
	}
	dir_name++;
	return (file_list);
}

void 				swap(t_file *tmp)
{
	t_file 			*swap;

	swap = malloc(sizeof(t_file));
	swap->name = tmp->next->name;
	swap->info = tmp->next->info;
	tmp->next->name = tmp->name;
	tmp->next->info = tmp->info;
	tmp->name = swap->name;
	tmp->info = swap->info;
	free(swap);
}

t_file 				*rOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	while (tmp->next != NULL)
	{
		if (my_strcmp(tmp->name, tmp->next->name) <= -1)
		{
			swap(tmp);
			tmp = file_list;
		}
		else
			tmp = tmp->next;
	}
	dir_name++;
	return (file_list);
}
