NAME = libmx.a
CC = clang

RAW = printchar print_unicode printstr print_strarr printint pow sqrt \
	itoa strncmp\
	\
	strlen swap_char str_reverse strdel del_strarr get_char_index strdup \
	strndup strcpy strncpy strcmp strcat strstr \
	count_words strnew strtrim strsplit strjoin file_to_str \
	\
	memset memcpy memccpy memcmp memchr memmem memrchr memmove \
	\
	atoi isspace isalpha isdigit get_len realloc \
	\

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(addprefix mx_, $(addsuffix .c, $(RAW))))
OBJ = $(addprefix $(OBJ_DIR), $(addprefix mx_, $(addsuffix .o, $(RAW))))

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc

all: install clean

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

install: $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

uninstall:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all