/*
** struct.h for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Wed Mar  2 15:47:29 2016 BEQUET Theo
** Last update Wed Mar  2 15:48:01 2016 BEQUET Theo
*/

#include "header.h"

typedef struct s_file t_file;

typedef struct s_option t_option;

typedef struct s_ls_option t_ls_option;

struct s_file
{
	char *name;
	struct stat info;
	t_file *next;
};

struct s_ls_option
{
	t_file *(*getFunc)(char *, t_file *); // -a ou -A ou -d
	t_file *(*affFunc)(char *, t_file *); // -l ou -L
	t_file *(*sortFunc)(char *, t_file *); // -t ou -r
};

struct s_option
{
	char opt;
	t_file *(*func)(char *, t_file *);
	t_option *next;
};