NAME_CLIENT		=
NAME_SERVER		=
S_MANDATORY		=
S_FILES			=	$(S_MANDATORY:%.c=%.o)
C_MANDATORY		=
C_FILES			=	$(C_MANDATORY:%.c=%.o)
S_BONUS			=
c_BONUS			=
HEADER			=
LIB				=
HEADER_BONUS	=
C_BONUS	 		=
S_BONUS			=
CC				=	cc
CFLAGS			=	-g3 -Wall -Wextra -Werror
VALGRIND		=	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
GDB				=	gdb --tui --args

all: libft
	make $(NAME_SERVER)
	make $(NAME_CLIENT)

$(NAME_SERVER): $(S_FILES)
	$(CC) $(CFLAGS) -I. $(S_FILES) $(LIB) -o $(NAME_SERVER)

$(S_FILES): $(S_MANDATORY)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) $(LIB) -o $(NAME_CLIENT)

$(C_FILES): $(C_MANDATORY)
	$(CC) $(CFLAGS)  -c $< -o $@

bonus:
	@make fclean
	@make C_MANDATORY="$(C_BONUS)" S_MANDATORY="$(S_BONUS)"

libft:
	make -C libfstonk

clean:
	rm -f $(S_FILES) $(C_FILES)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME_CLIENT)

gdb: all
	$(GDB) ./$(NAME_CLIENT)

.PHONY:	all clean fclean re bonus libft valgrind gdb