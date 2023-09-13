# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edboutil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 17:05:14 by edboutil          #+#    #+#              #
#    Updated: 2022/12/24 17:05:15 by edboutil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
NAME_SERV		=	server
SRCS_SERV		=	SRCS/server.c \
					UTILS/printf.c UTILS/list.c
OBJS_SERV		=	$(addprefix ${OBJS_DIR}, $(SRCS_SERV:.c=.o))
DEP_SERV		=	$(addprefix $(OBJS_DIR), $(SRCS_SERV:.c=.d))

NAME_CLI		=	client
SRCS_CLI		=	SRCS/client.c \
					UTILS/printf.c UTILS/atoi.c UTILS/is_number.c
OBJS_CLI		=	$(addprefix ${OBJS_DIR}, $(SRCS_CLI:.c=.o))
DEP_CLI			=	$(addprefix $(OBJS_DIR), $(SRCS_CLI:.c=.d))

HEAD			=	INCLUDES/

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror
FLAGS			+=	-MMD -MP

# RULES -------------------------------------------------------------
all:				$(NAME_SERV) $(NAME_CLI)

$(NAME_SERV):		$(OBJS_SERV)
					$(CC) $(FLAGS) $(OBJS_SERV) -o $(NAME_SERV)

$(NAME_CLI):		$(OBJS_CLI)
					$(CC) $(FLAGS) $(OBJS_CLI) -o $(NAME_CLI)

-include $(DEP_SERV) $(DEP_CLI)
$(OBJS_DIR)%.o:		%.c | dir
					$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)UTILS
					@mkdir -p $(OBJS_DIR)SRCS

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME_SERV) $(NAME_CLI)

re:					fclean all

.PHONY:				all dir clean fclean re