# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 13:52:48 by jsebasti          #+#    #+#              #
#    Updated: 2022/12/14 13:52:48 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 
HEADER = 
MKFL = Makefile
OBJ_DIR = obj/
DEP_DIR = dep/
INC_DIR	= inc/

SRC	= 

# ----Libft----
LFTDIR	= $(INC_DIR)/Libft
SRC		+= 
# =============

# ----Printf----
PRINTFDIR	= $(INC_DIR)/printf

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -W -O3 -Ofast
LIBC = ar -rcs
# =============

# -------------
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
# =============

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

$(NAME)::
	@echo "Hello, i'm already compiled 😇"

-include $(DEP)

clean:
	$(RM) $(OBJ)

fclean:
	@$(MAKE) clean
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re