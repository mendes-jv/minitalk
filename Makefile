# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:07:58 by jovicto2          #+#    #+#              #
#    Updated: 2023/11/06 12:12:46 by jovicto2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

# Variables

CLIENT_NAME			:= client
SERVER_NAME			:= server

SOURCES_DIR			:= sources/
OBJECTS_DIR			:= objects/
HEADERS_DIR			:= includes/
LIBRARIES_DIR		:= libraries/
LIBFT_DIR			:= $(addprefix $(LIBRARIES_DIR), libft/)
LIBFT_FILE 			:= libft.a

MAKE				:= make
MAKE_LIBS			:= $(MAKE) -C
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -Wunreachable-code -Ofast -O3 -g3
FSANITIZE			:= -fsanitize=address
MKDIR				:= mkdir -p
RM					:= rm -rf

# Sources

CLIENT_FILES		:= client
SERVER_FILES		:= server

CLIENT_SOURCES		:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(CLIENT_FILES)))
SERVER_SOURCES		:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(SERVER_FILES)))
CLIENT_OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(CLIENT_FILES)))
SERVER_OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(SERVER_FILES)))
LIBFT				:= $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

LIBFT_HEADER		:= $(addprefix $(LIBFT_DIR), includes/libft.h)
HEADERS				:= -I $(HEADERS_DIR)

# colors
GREEN  				:= \033[0;32m
RESET  		 		:= \033[0m

# Rules

.PHONY: all clean fclean re

all: libraries programs
	@printf "$(GREEN)Compiled $(CLIENT_NAME) and $(SERVER_NAME) successfully!$(RESET)\n"

libraries: $(LIBFT)

programs: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJECTS)
	@$(CC) $(CFLAGS) $(FSANITIZE) $(CLIENT_OBJECTS) $(LIBFT) -o $(CLIENT_NAME) $(INCLUDES)

$(SERVER_NAME): $(SERVER_OBJECTS)
	@$(CC) $(CFLAGS) $(FSANITIZE) $(SERVER_OBJECTS) $(LIBFT) -o $(SERVER_NAME) $(INCLUDES)

$(LIBFT):
	@$(MAKE_LIBS) $(LIBFT_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean: cleanlibft
	@$(RM) $(OBJECTS_DIR)
	@printf "$(GREEN)Cleaned objects from $(CLIENT_NAME) and $(SERVER_NAME) successfully!$(RESET)\n"

cleanlibft:
	@$(MAKE_LIBS) $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@printf "$(GREEN)Cleaned $(CLIENT_NAME) and $(SERVER_NAME) successfully!$(RESET)\n"

re: fclean
	@$(MAKE)