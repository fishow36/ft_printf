# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 21:34:43 by mbrogg            #+#    #+#              #
#    Updated: 2019/11/19 21:20:46 by mbrogg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMPILER = gcc
FLAGS = -g
INC = -I includes/
SRCS = ft_atoi.c \
	ft_strmap.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_spaces.c \
	ft_spaces_rev.c \
	ft_strisempty.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_free_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstdelone_s.c \
	ft_lstnew_fd.c \
	ft_strjoin_s.c \
	get_next_line.c \

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
	@ar rc $(NAME) $(SRCS:.c=.o)
	@ranlib	$(NAME)

%.o: %.c
	@$(COMPILER) $(FLAGS) $(INC) $< -c -o $@

clean:
	@rm -f $(SRCS:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
