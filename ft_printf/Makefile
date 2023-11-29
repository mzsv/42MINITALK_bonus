# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 03:33:30 by amenses-          #+#    #+#              #
#    Updated: 2022/12/05 22:30:14 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c \
					ft_printf_utils_0.c ft_printf_utils_1.c \
					ft_printf_utils_2.c ft_printf_utils_3.c \
					ft_printf_utils_4.c ft_printf_utils_5.c \
					ft_printf_utils_6.c ft_printf_utils_7.c \

OBJS			=	$(SRCS:.c=.o)

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

bonus:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:					fclean $(NAME)

.PHONY:			all clean fclean re bonus
