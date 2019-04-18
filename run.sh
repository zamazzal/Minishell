make -C libft re
make -C libft clear
gcc -Wall -Wextra -Werror srcs/builtins/*.c srcs/commands.c srcs/main.c srcs/env.c srcs/tools.c srcs/messages.c -I includes -I libft/ libft/libft.a -I srcs/builtins/ls/includes srcs/builtins/ls/srcs/*
echo "done"
