SRC=ft_realloc.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strndup.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_calloc.c ft_lstpushback.c ft_lstsize.c ft_lstlast.c ft_treenew.c ft_nodeaddleft.c ft_nodeaddright.c ft_nbrlen.c ft_putnstr.c
INCF:=	../includes/libft.h\
		../includes/struct_lsl.h\
		../includes/ft_ls.h
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
RED=\033[0;31m
LBLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NAME)

$(NAME): $(SRC) $(INCF)
	@echo "${RED}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) -c $(CFLAGS) $(SRC) -I ../includes/
	@echo "${LBLUE}ar rc $(NAME)${NC}"
	@ar rc $(NAME) $(OBJ)
	@echo "${ORANGE}ranlib $(NAME)${NC}"
	@ranlib $(NAME)
	@rm -f $(OBJ)

clean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ)

fclean:
	@echo "${CYAN}Delete OBJ files${NC}"
	@rm -rf $(OBJ)
	@echo "${CYAN}Delete $(NAME) file${NC}"
	@rm -rf $(NAME)

re: fclean all clean
