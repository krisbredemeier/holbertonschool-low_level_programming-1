CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic
OBJ = shell.c read_line.c
DEPS =
NAME = c_shell

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
