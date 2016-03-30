/*
** get_fonction.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Thu Mar  3 11:20:12 2016 BEQUET Theo
** Last update Thu Mar  3 11:20:13 2016 BEQUET Theo
*/

#include "header.h"

t_file 				*noGetOption(char *dir_name, t_file *file_list)
{
	DIR             *dir;
	struct dirent   *ent;

	if ((dir = opendir(dir_name)) == NULL)
		return (NULL);
	while (readdir(dir)->d_name[0] == '.');
	ent = readdir(dir);
	file_list->next = NULL;
	file_list->name = ent->d_name;
	lstat(my_strcat(my_strdup(dir_name), ent->d_name), &file_list->info);
	while ((ent = readdir(dir)) != NULL)
	{
		if (ent->d_name[0] != '.')
		    file_list = addStruct(dir_name, ent->d_name, file_list);
	}
	closedir(dir);
	return (file_list);
}

t_file 				*aOption(char *dir_name, t_file *file_list)
{
	DIR             *dir;
	struct dirent   *ent;

	if ((dir = opendir(dir_name)) == NULL)
		return (NULL);
	ent = readdir(dir);
	file_list->next = NULL;
	file_list->name = ent->d_name;
	lstat(my_strcat(my_strdup(dir_name), ent->d_name), &file_list->info);
	while ((ent = readdir(dir)) != NULL)
	{
	    file_list = addStruct(dir_name, ent->d_name, file_list);
	}
	closedir(dir);
	return (file_list);
}

t_file 				*AOption(char *dir_name, t_file *file_list)
{
	DIR             *dir;
	struct dirent   *ent;

	if ((dir = opendir(dir_name)) == NULL)
		return (NULL);
	ent = readdir(dir);
	file_list->next = NULL;
	file_list->name = ent->d_name;
	lstat(my_strcat(my_strdup(dir_name), ent->d_name), &file_list->info);
	while ((ent = readdir(dir)) != NULL)
	{
		if (my_strcmp(ent->d_name, ".") != 0 &&
			my_strcmp(ent->d_name, "..") != 0)
	    	file_list = addStruct(dir_name, ent->d_name, file_list);
	}
	closedir(dir);
	return (file_list);
}

t_file 				*dOption(char *dir_name, t_file *file_list)
{
	DIR             *dir;
	struct dirent   *ent;

	if ((dir = opendir(dir_name)) == NULL)
		return (NULL);
	while (readdir(dir)->d_name[0] == '.');
	ent = readdir(dir);
	file_list->next = NULL;
	file_list->name = ent->d_name;
	lstat(ent->d_name, &file_list->info);
	while ((ent = readdir(dir)) != NULL)
	{
		if (my_strcmp(ent->d_name, ".") != 0 &&
			my_strcmp(ent->d_name, "..") != 0)
	    file_list = addStruct(dir_name, ent->d_name, file_list);
	}
	closedir(dir);
	return (file_list);
}

t_file *addStruct(char *dir_name, char *file_name, t_file *next)
{
	t_file *tmp;

	tmp = malloc(sizeof(t_file));
	tmp->name = file_name;
	lstat(my_strcat(my_strdup(dir_name), file_name), &tmp->info);
	tmp->next = next;
	return (tmp);
}
