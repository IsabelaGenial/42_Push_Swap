NAME			=	push_swap
MANDATORY		=   push_swap.c moves_list_a.c dcll_function.c moves_list_b.c checks.c sort.c free.c radix_sort.c
FILES			=	$(MANDATORY:%.c=%.o)
BONUS			=
HEADER			= push_swap.h
LIB				= ./libfstonk/libft.a
CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror
VALGRIND		=	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: libft $(NAME)

$(NAME): $(FILES)
	@$(CC) $(CFLAGS) -I. $(FILES) $(LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make fclean
	@make MANDATORY="$(BONUS)"

libft:
	make -C libfstonk

clean:
	@rm -f $(FILES)

fclean: clean
	@rm -f $(NAME)
	make fclean -Clibfstonk

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME) 3 6 9 8 5 2 1 4 7 

gdb: all
	$(GDB) ./$(NAME) 12 325 96 7 4 2 6 0 3 8 56 1 45 23 5 1551 521 4693

.PHONY:	all clean fclean re bonus libft valgrind gdb
