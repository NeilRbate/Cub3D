GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

SRCS_EXEC       =		src/main.c \
							src/exec/launch.c \
							src/exec/minimap.c \
							src/exec/raycast.c \
							src/exec/texture.c \
							src/exec/print.c \
								src/utils/init_all.c \
								src/utils/keys.c \
								src/utils/colors.c \
								src/utils/inttofloat.c \
								src/utils/draw.c \
								src/utils/free.c \
									src/parsing/file.c \
									src/parsing/list.c \
									src/parsing/parsing.c \
									src/parsing/mapelem.c \
									src/parsing/customft.c \
									src/parsing/color.c \
									src/parsing/char_map.c \
									src/parsing/checkwall.c \
									src/parsing/chartoint.c \

OBJS       =		$(SRCS_EXEC:.c=.o) $(SRCS_PARS:.c=.o)

RM              =		rm -f

CC              =		gcc

FLAGS           =		-Wall -Wextra -Werror

HEADERS			=		-I include

LIB_PATH		=		-L. libft/libft.a 

NAME            =		cub3D

MLX = mlx/libmlx.a
.c.o:
				@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
				@$(CC) $(FLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME):        $(OBJS)
				@make -C libft
				@$(CC) $(FLAGS) -lm -lmlx -framework OpenGL -framework AppKit $(OBJS) $(HEADERS) $(LIB_PATH) -o $(NAME)
				@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)


all:            $(NAME)

clean:			
				@make clean -C libft
				@$(RM) $(OBJS)
				@printf $(RED)"\r\033[K➜ ["$(NAME)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:         clean
				@make fclean -C libft
				@$(RM) $(NAME)
				@printf $(RED)"\r\033[K➜ ["$(NAME)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re:             fclean all
