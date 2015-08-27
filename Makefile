SRC:=	src/create_node.c\
		src/error.c\
		src/ft_argsmisc.c\
		src/ft_arguments.c\
		src/insert_data.c\
		src/main.c\
		src/misc.c\
		src/misclsl.c\
		src/print.c\
		src/print_lsl.c\
		src/print_miscinfos.c\
		src/print_names.c\
		src/print_right.c\
		src/read.c\
		src/set_up.c\
		src/sort.c\
		src/stat_to_llstat.c\
		src/take_stats.c

INCF:=	includes/libft.h\
		includes/ft_ls.h\
		includes/struct_lsl.h
OBJ:=$(SRC.c=.o)

# Lib includes
INC=-I includes
LIB=-L libft -lftprintf -lacl

# Options can be changed
CFLAGS:=-Wall -Wextra -Werror -g
CC:=gcc
NAME:=ft_ls

# Sweet colors just for swag :)

RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all:$(NAME)

$(NAME): $(SRC) $(INCF) $(LIBFTSRC)
	@make -s -C libft
	@echo "${LBLUE}Compile $(NAME)${NC}"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(INC) -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
