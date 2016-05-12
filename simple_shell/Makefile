CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic
OBJ = shell.c read_line.c string_split.c
DEPS = shell_head.h
NAME = c_shell

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
