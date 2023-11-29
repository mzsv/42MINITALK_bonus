# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 23:56:06 by amenses-          #+#    #+#              #
#    Updated: 2022/12/11 00:56:40 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	ft_minitalk_utils_0.c ft_minitalk_utils_1.c \

OBJS			=	$(SRCS:.c=.o)

CLIENT			=	client
SERVER			=	server
CLIENT_BONUS	=	client_bonus
SERVER_BONUS	=	server_bonus
PRINTF			=	ft_printf/libftprintf.a

all:				$(CLIENT) $(SERVER)

$(CLIENT):			$(OBJS)
						$(MAKE) -C ft_printf
						$(CC) $(CFLAGS) client.c $(OBJS) $(PRINTF) -o $(CLIENT)

$(SERVER):			$(OBJS)
						$(CC) $(CFLAGS) server.c $(OBJS) $(PRINTF) -o $(SERVER)

$(CLIENT_BONUS):	$(OBJS)
						$(MAKE) -C ft_printf
						$(CC) $(CFLAGS) client_bonus.c $(OBJS) $(PRINTF) -o $(CLIENT_BONUS)

$(SERVER_BONUS):	$(OBJS)
						$(CC) $(CFLAGS) server_bonus.c $(OBJS) $(PRINTF) -o $(SERVER_BONUS)

bonus:				$(CLIENT_BONUS) $(SERVER_BONUS)

clean:
					$(MAKE) clean -C ft_printf
					$(RM) $(OBJS)

fclean:				clean
						$(MAKE) fclean -C ft_printf
						$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:					fclean all
