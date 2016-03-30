/*
** ls.c for  in /Users/bequet_t/Documents/C/My_ls
** 
** Made by BEQUET Theo
** Login   <bequet_t@etna-alternance.net>
** 
** Started on  Wed Mar  2 16:44:55 2016 BEQUET Theo
** Last update Wed Mar  2 16:44:56 2016 BEQUET Theo
*/

#include "header.h"

int 			my_ls(int argc, char **argv)
{
	int 		i;
	t_ls_option *option;
	t_file		*file;

	i = 1;
	file = malloc(sizeof(t_file));
	option = malloc(sizeof(t_ls_option));
	option = defOption(option, argv);
	while (argv[i] != NULL)
	{
		if (argv[i][0] != '-')
		{
			execFonc(argv[i], option, file);
			argc++;
		}
		i++;
	}
	if (argc == 0)
	{
		file = (*option->getFunc)("./", file);
	       	file = (*option->sortFunc)("./", file);
		(*option->affFunc)("./", file);
	}
	return (0);
}

t_ls_option 	*defOption(t_ls_option *option, char **argv)
{
	int 		i;
	t_option 	*opt_list;
	
	i = 1;
	option->getFunc = noGetOption;
	option->affFunc = noAffOption;
	option->sortFunc = noSortOption;
	opt_list = initOption();
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'a' || argv[i][1] == 'A' || argv[i][1] == 'd')
				option->getFunc = defOptionFunc(opt_list, argv[i][1]);
			else if (argv[i][1] == 'l' || argv[i][1] == 'L')
				option->affFunc = defOptionFunc(opt_list, argv[i][1]);
			else if (argv[i][1] == 't' || argv[i][1] == 'r')
				option->sortFunc = defOptionFunc(opt_list, argv[i][1]);
		}
		i++;
	}
	return (option);
}

t_file 			*(* defOptionFunc(t_option *opt_list, char opt))(char *, t_file *)
{
	t_option *tmp;

	tmp = opt_list;
	while (tmp != NULL)
	{
		if (tmp->opt == opt)
			return (tmp->func);
		tmp = tmp->next;
	}
	return (NULL);
}


t_option 		*initOption()
{
	t_option 	*option;

	option = malloc(sizeof(t_option));
	option->opt = 'a';
	option->func = aOption;
	option->next = NULL;
	option = initOption2('A', AOption, option);
	option = initOption2('d', dOption, option);
	option = initOption2('l', lOption, option);
	option = initOption2('L', LOption, option);
	option = initOption2('t', tOption, option);
	option = initOption2('r', rOption, option);
	return (option);
}

t_option 		*initOption2(char opt, t_file *(*func)(char *, t_file *), t_option *next)
{
	t_option *new_option;

	new_option = malloc(sizeof(t_option));
	new_option->opt = opt;
	new_option->func = func;
	new_option->next = next;
	return (new_option);
}


