FILENAMES_GENERAL = stack_utils.c stack_utils_add.c stack_operations.c \
	sort_utils.c ft_strtol.c process_input.c
FILENAMES = main.c sorter.c sorter_utils.c \
	ps_pushes.c ps_rotations.c ps_rrotations.c ps_swaps.c
FILENAMES_BONUS = main_bonus.c
FILENAMES_VISUAL = visual.c
SOURCES_GENERAL = $(addprefix ./srcs/general/,$(FILENAMES_GENERAL))
SOURCES = $(addprefix ./srcs/main/,$(FILENAMES)) $(SOURCES_GENERAL)
SOURCES_BONUS = $(addprefix ./srcs/bonus/,$(FILENAMES_BONUS)) $(SOURCES_GENERAL)
SOURCES_VISUAL = $(addprefix ./srcs/visual/,$(FILENAMES_VISUAL)) $(SOURCES_GENERAL)
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
FILENAMES_HEADERS = push_swap.h push_swap_sorter.h
HEADERS = $(addprefix ./includes/,$(FILENAMES_HEADERS))
NAME = push_swap
BONUS_NAME = checker
VISUAL_NAME = visualize
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
OBJECTS_VISUAL = $(SOURCES_VISUAL:.c=.o)
INCLUDE_PATH = ./includes/ $(PRINTF_PATH) $(PRINTF_PATH)/libft
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
	@norminette $(SOURCES)
	@norminette $(SOURCES_BONUS)
	@norminette $(SOURCES_VISUAL)
	@norminette $(HEADERS)