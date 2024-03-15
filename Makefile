# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:49:54 by gchamore          #+#    #+#              #
#    Updated: 2024/03/15 15:31:23 by gchamore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -I./headers/

RM = rm -rf

SRCS_SERVER = srcs/server.c srcs/tools.c

SRCS_CLIENT = srcs/client.c srcs/tools.c

OBJ_DIR = objs

OBJS_SERVER = $(addprefix $(OBJ_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRCS_CLIENT:.c=.o))

DEPS = $(OBJS:.o=.d) $(OBJS_BONUS:.o=.d)

all: first_header $(NAME) second_header

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(MAKE) -sC ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

$(CLIENT): $(OBJS_CLIENT)
	$(MAKE) -sC ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC)  $(CFLAGS) -MMD -c -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re



info: header

first_header:
	@echo "\n $$FIRST_HEADER \n"

define FIRST_HEADER

⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀

endef
export FIRST_HEADER

second_header:
	@echo "\n$$SECOND_HEADER \n"

define SECOND_HEADER
██████████████████████████████████████████████████████████████████████
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌  ██╗  ██╗██████╗     ██████╗  ██████╗ ██████╗ ███╗   ██╗         ▐█
█▌  ██║  ██║╚════██╗    ██╔══██╗██╔═══██╗██╔══██╗████╗  ██║         ▐█
█▌  ███████║ █████╔╝    ██████╔╝██║   ██║██████╔╝██╔██╗ ██║         ▐█
█▌  ╚════██║██╔═══╝     ██╔══██╗██║   ██║██╔══██╗██║╚██╗██║         ▐█
█▌       ██║███████╗    ██████╔╝╚██████╔╝██║  ██║██║ ╚████║         ▐█
█▌       ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝         ▐█
█▌                                                                  ▐█
█▌  ████████╗ ██████╗      ██████╗ ██████╗ ██████╗ ███████╗    ██╗  ▐█
█▌  ╚══██╔══╝██╔═══██╗    ██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║█████╗      ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║██╔══╝      ╚═╝  ▐█
█▌     ██║   ╚██████╔╝    ╚██████╗╚██████╔╝██████╔╝███████╗    ██╗  ▐█
█▌     ╚═╝    ╚═════╝      ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝    ╚═╝  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
██████████████████████████████████████████████████████████████████████
endef
export SECOND_HEADER

header:
	@echo "$$FIRST_HEADER"
	@echo "$$SECOND_HEADER"
