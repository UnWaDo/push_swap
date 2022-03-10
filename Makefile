SOURCES = main.c stack_utils.c stack_operations.c \
	ps_pushes.c ps_rotations.c ps_rrotations.c ps_swaps.c \
	sort_utils.c ft_strtol.c
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
HEADERS = push_swap.h
NAME = push_swap
OBJECTS = $(SOURCES:.c=.o)
INCLUDE_PATH = $(PRINTF_PATH) $(PRINTF_PATH)/libft
CFLAGS = -Wall -Wextra -Werror -fsanitize=address $(addprefix -I,$(INCLUDE_PATH))
.PHONY: all clean fclean re bonus norm

$(NAME): $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) -o $(NAME) $(CINCLUDES)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(NAME)

clean:
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)