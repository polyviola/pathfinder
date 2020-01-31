CC = clang
LIB = libmx.a
NAME = pathfinder

RAW = main mx_p_algoritm mx_p_backtrack mx_p_check_err mx_p_check_err2 \
	mx_p_conclusion mx_p_err mx_p_err1 mx_p_err2 mx_p_matrix mx_p_printpath \

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libmx/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(RAW)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(RAW)))
LIB_PATH = $(addprefix $(LIB_DIR), $(LIB))

WFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -Iinc -Ilibmx/inc
CFLAGS = -Ofast -march=native -pipe -fomit-frame-pointer -flto
DFLAGS = -O0 -g3 -fsanitize=address

all: install

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -sC $(LIB_DIR) -f Makefile install

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(WFLAGS) $(LFLAGS) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_PATH)

install: $(LIB) $(NAME)

clean:
	@make -sC $(LIB_DIR) -f Makefile clean
	@rm -rf $(OBJ_DIR)

uninstall:
	@make -sC $(LIB_DIR) -f Makefile uninstall
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

reinstall: uninstall install