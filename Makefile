# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 15:47:43 by zamazzal          #+#    #+#              #
#    Updated: 2019/04/29 13:05:54 by zamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/
OBJ_PATH = obj/

builtins_SRCS = $(addprefix $(SRCS_PATH), builtins/)
commands_SRCS = $(addprefix $(SRCS_PATH), commands/)
messages_SRCS = $(addprefix $(SRCS_PATH), messages/)
tools_SRCS = 	$(addprefix $(SRCS_PATH), tools/)

builtins_OBJ =	$(addprefix $(OBJ_PATH), builtins/)
commands_OBJ =	$(addprefix $(OBJ_PATH), commands/)
messages_OBJ =	$(addprefix $(OBJ_PATH), messages/)
tools_OBJ = 	$(addprefix $(OBJ_PATH), tools/)

LIBFT_PATH = libft/
Libft = -L $(LIBFT_PATH) -lft
INCLUDES = -I includes/ -I $(LIBFT_PATH)


builtins =		builtins.c	\
				cd.c		\
				env.c		\
				echo.c		\
				setenv.c	\
				unsetenv.c	\

commands= 		exec.c		\
				commands.c	\

messages=		messages1.c \

tools= 			tools1.c	\
				tools2.c	\
				tools3.c	\
				main.c		\

SRCS = $(addprefix $(builtins_SRCS), $(builtins)) $(addprefix $(commands_SRCS), $(commands)) $(addprefix $(messages_SRCS), $(messages)) $(addprefix $(tools_SRCS), $(tools))
OBJ = $(addprefix $(builtins_OBJ), $(builtins:.c=.o)) $(addprefix $(commands_OBJ), $(commands:.c=.o)) $(addprefix $(messages_OBJ), $(messages:.c=.o)) $(addprefix $(tools_OBJ), $(tools:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(Libft) $(INCLUDES) -o $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(builtins_OBJ)%.o: $(builtins_SRCS)%.c
	@mkdir -p $(builtins_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(commands_OBJ)%.o: $(commands_SRCS)%.c
	@mkdir -p $(commands_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(messages_OBJ)%.o: $(messages_SRCS)%.c
	@mkdir -p $(messages_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(tools_OBJ)%.o: $(tools_SRCS)%.c
	@mkdir -p $(tools_OBJ)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\x1B[96mObjects Files \x1B[90;0m[\x1B[34;1m $(notdir $(OBJ)) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re: fclean all

.PHONY: all, clean, fclean, re
