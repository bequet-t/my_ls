##
## Makefile for  in /Users/bequet_t/Documents/C/My_ls
## 
## Made by BEQUET Theo
## Login   <bequet_t@etna-alternance.net>
## 
## Started on  Mon Feb 29 10:27:10 2016 BEQUET Theo
## Last update Mon Feb 29 10:27:28 2016 BEQUET Theo
##

CC =	gcc
NAME =	my_ls
SRC =	$(wildcard *.c)
OBJ =	$(SRC:%.c=%.o)
RM =	rm -f
CFLAGS = -W -Wall -Werror

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all