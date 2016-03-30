/*
** header.h for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Wed Mar  2 15:42:18 2016 BEQUET Theo
** Last update Wed Mar  2 15:42:19 2016 BEQUET Theo
*/

#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include "struct.h"

// Fonctions basiques
void  			my_putchar(char c);

void  			my_putstr(char *str);

void  			my_putnstr(char *str, int n);

char 			*my_strcat(char *dest, char *src);

int 			my_strlen(char *str);

void			my_put_nbr(int n);

int 			my_strcmp(char *str1, char *str2);

char 			*my_strdup(char *str);

int 			my_ls(int argc, char **argv);

int 			execFonc(char *dir_name, t_ls_option *option, t_file *file);

t_ls_option 	*defOption(t_ls_option *option, char **argv);

t_option 		*initOption();

t_option 		*initOption2(char opt, t_file *(*func)(char *, t_file *), t_option *next);

t_file 			*(* defOptionFunc(t_option *opt_list, char opt))(char *, t_file *);

t_file 			*addStruct(char *dir_name, char *file_name, t_file *next);

t_file 			*noGetOption(char *dir_name, t_file *file_list);

t_file 			*aOption(char *dir_name, t_file *file_list);

t_file 			*AOption(char *dir_name, t_file *file_list);

t_file 			*dOption(char *dir_name, t_file *file_list);

t_file 			*noAffOption(char *dir_name, t_file *file_list);

t_file 			*lOption(char *dir_name, t_file *file_list);

void			affPerm(t_file *file);

void			affGroup(t_file *file);

t_file 			*LOption(char *dir_name, t_file *file_list);

t_file			*noSortOption(char *dir_name, t_file *file_list);

t_file 			*rOption(char *dir_name, t_file *file_list);

t_file 			*tOption(char *dir_name, t_file *file_list);

void 			swap(t_file *tmp);

void			freeListe(t_file *file);

#endif