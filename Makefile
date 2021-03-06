# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubedat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 19:30:56 by adubedat          #+#    #+#              #
#    Updated: 2016/01/03 15:09:54 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC = libft/ft_putchar.c libft/ft_putstr.c libft/ft_putendl.c libft/ft_putnbr.c \
	  libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
	  libft/ft_putnbr_fd.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_strcpy.c \
	  libft/ft_strncpy.c libft/ft_strcat.c libft/ft_strncat.c libft/ft_strlcat.c \
	  libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c \
	  libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
	  libft/ft_toupper.c libft/ft_tolower.c libft/ft_memset.c libft/ft_bzero.c \
	  libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c \
	  libft/ft_memcmp.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c \
	  libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c \
	  libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c \
	  libft/ft_strtrim.c libft/ft_strsplit.c libft/ft_puttab2d.c libft/ft_itoa.c \
	  libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c \
	  libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_intlen.c libft/ft_swap.c \
	  libft/ft_rrange.c libft/ft_power.c libft/ft_strchr.c libft/ft_strrchr.c \
	  libft/ft_strstr.c libft/ft_strnstr.c libft/ft_memalloc.c libft/ft_memdel.c \
	  libft/ft_malloctab2d.c libft/ft_itoa_lli.c libft/ft_itoa_ulli.c \
	  libft/ft_lli_len.c libft/ft_ulli_len.c libft/ft_itoa_base_lli.c \
	  libft/ft_itoa_base_ulli.c libft/ft_ulli_len_base.c libft/ft_addr.c \
	  libft/ft_strjoin_free_s2.c libft/ft_strsub_free.c libft/ft_strjoin_free_s1.c \
	  libft/ft_putwchar.c libft/ft_atoi_base.c libft/ft_putwstr.c \
	  check_flags.c ft_printf.c signed_decimal.c apply_flags.c string.c \
	  unsigned_decimal.c char.c pointer.c

HEADERS	= -I/libft/includes/

OBJECTS	= $(subst .c,.o,$(SRC))

WFLAGS	= -Wall -Werror -Wextra

CC		= gcc

.SILENT:

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

all: $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) $(HEADERS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@ "
	printf "\033[0m\n"

clean:
	rm -rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

.PHONY: re fclean clean all
