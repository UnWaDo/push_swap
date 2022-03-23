SOURCES_GENERAL = stack_utils.c stack_utils_add.c stack_operations.c \
	sort_utils.c ft_strtol.c process_input.c
SOURCES = main.c sorter.c sorter_utils.c $(SOURCES_GENERAL) \
	ps_pushes.c ps_rotations.c ps_rrotations.c ps_swaps.c
SOURCES_BONUS = main_bonus.c $(SOURCES_GENERAL)
SOURCES_VISUAL = visual.c $(SOURCES_GENERAL)
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
HEADERS = push_swap.h
NAME = push_swap
BONUS_NAME = checker
VISUAL_NAME = visualize
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
OBJECTS_VISUAL = $(SOURCES_VISUAL:.c=.o)
INCLUDE_PATH = $(PRINTF_PATH) $(PRINTF_PATH)/libft
CFLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCLUDE_PATH)) -fsanitize=address -g
.PHONY: all clean fclean re bonus norm visual

$(NAME): $(PRINTF) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) -o $(NAME) $(CINCLUDES)

all: $(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(PRINTF) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(PRINTF) -o $(BONUS_NAME) $(CINCLUDES)

clean:
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_VISUAL)

fclean: clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(VISUAL_NAME)

visual: $(VISUAL_NAME)

$(VISUAL_NAME): $(PRINTF) $(OBJECTS_VISUAL)
	$(CC) $(CFLAGS) $(OBJECTS_VISUAL) $(PRINTF) -o $(VISUAL_NAME) $(CINCLUDES)

re: fclean all

norm:
	norminette $(SOURCES) $(HEADERS)