# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efirmino <efirmino@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 17:43:00 by efirmino          #+#    #+#              #
#    Updated: 2023/03/18 11:12:17 by efirmino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

LIBFT_SRC		=	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
					libft/ft_isalnum.c libft/ft_isalpha.c \
					libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
					libft/ft_itoa.c libft/ft_memchr.c \
					libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
					libft/ft_memset.c libft/ft_putchar_fd.c \
					libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
					libft/ft_putstr_fd.c libft/ft_strchr.c \
					libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
					libft/ft_strlcat.c libft/ft_strlcpy.c \
					libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
					libft/ft_strnstr.c libft/ft_strrchr.c \
					libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c \
					libft/ft_toupper.c libft/ft_split.c libft/ft_strtrijoin.c

GNL_SRC			=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c 

FT_PRINTF_SRC	=	ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
					ft_printf/ft_printf_utils2.c


SRCS			=	$(LIBFT_SRC) $(GNL_SRC) $(FT_PRINTF_SRC)

OBJS			=	$(SRCS:.c=.o)

FLAGS			=	-Wall -Wextra -Werror

CC				=	cc

RM				=	rm -f

NAME			=	libft.a

PROJECT			=	libft

.c.o:
		@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
		@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

all:	$(NAME)

clean:
		@$(RM) $(OBJS)
		@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean:	clean
		@$(RM) $(NAME)
		@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re:	fclean all