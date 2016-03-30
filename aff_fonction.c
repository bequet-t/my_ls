/*
** aff_fonction.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Thu Mar  3 14:10:59 2016 BEQUET Theo
** Last update Thu Mar  3 14:11:00 2016 BEQUET Theo
*/

#include "header.h"

t_file 				*noAffOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	my_putstr(dir_name);
	my_putstr(":\n");
	while (tmp->next != NULL)
	{
		my_putstr(tmp->name);
		my_putstr("\n");
		tmp = tmp->next;
	}
	my_putstr("\n");
	return (file_list);
}

t_file 				*lOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	my_putstr(dir_name);
	my_putstr(":\n");
	while (tmp->next != NULL)
	{
		affPerm(tmp);
		affGroup(tmp);
		my_putstr(tmp->name);
		my_putstr("\n");
		tmp = tmp->next;
	}
	return (file_list);
}

void 				affPerm(t_file *file)
{
	my_putstr((S_ISDIR(file->info.st_mode)) ? "d" : "-");
	my_putstr((file->info.st_mode & S_IRUSR) ? "r" : "-");
	my_putstr((file->info.st_mode & S_IWUSR) ? "w" : "-");
	my_putstr((file->info.st_mode & S_IXUSR) ? "x" : "-");
	my_putstr((file->info.st_mode & S_IRGRP) ? "r" : "-");
	my_putstr((file->info.st_mode & S_IWGRP) ? "w" : "-");
	my_putstr((file->info.st_mode & S_IXGRP) ? "x" : "-");
	my_putstr((file->info.st_mode & S_IROTH) ? "r" : "-");
	my_putstr((file->info.st_mode & S_IWOTH) ? "w" : "-");
	my_putstr((file->info.st_mode & S_IXOTH) ? "x" : "-");
	my_putstr(S_ISLNK(file->info.st_mode) ? "@ " : "  ");
	my_put_nbr(file->info.st_nlink);
	my_putstr("\t");
}

void				affGroup(t_file *file)
{
	int 			n;

	n = my_strlen(ctime(&file->info.st_mtime)) - 1;
	my_putstr(getpwuid(file->info.st_uid)->pw_name);
	my_putstr("\t");
	my_putstr(getgrgid(file->info.st_gid)->gr_name);
	my_putstr("\t");
	my_put_nbr(file->info.st_size);
	my_putstr("\t");
	my_putnstr(ctime(&file->info.st_mtime), n);
	my_putstr("  ");
}

t_file 				*LOption(char *dir_name, t_file *file_list)
{
	t_file 			*tmp;

	tmp = file_list;
	my_putstr(dir_name);
	my_putstr(":\n");
	while (tmp->next != NULL)
	{
		my_putstr(tmp->name);
		my_putstr("\t");
		tmp = tmp->next;
	}
	return (file_list);
}
