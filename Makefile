# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 13:52:48 by jsebasti          #+#    #+#              #
#    Updated: 2023/01/24 16:40:15 by jsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLI_BONUS	=	client_bonus
SRV_BONUS	=	server_bonus
SRV	   =	server
CLI    =	client
MKFL = Makefile
OBJ_S_DIR = objs/
OBJ_C_DIR = objc/
OBJ_S_B_DIR = objbs/
OBJ_C_B_DIR = objbc/
INC_DIR	= inc/

# ----Server----
SRC_S = server.c
SRC_S_B = server_bonus.c

# ----Client----
SRC_C = client.c
SRC_C_B = client_bonus.c

# ----Libft----
LFTDIR	= $(INC_DIR)Libft
# =============

# ----Printf----
PRINTFDIR	= $(INC_DIR)printf

# -------------
RM = rm -rf
MP = mkdir -p
CFLAGS = -Werror -Wextra -Wall -W -O3 -Ofast
LIBC = ar -rcs
# =============

# ----OBJ y DEP Server----
OBJ_S = $(addprefix $(OBJ_S_DIR), $(SRC_S:.c=.o))
DEP_S = $(addsuffix .d, $(basename $(OBJ_S)))

OBJ_S_B = $(addprefix $(OBJ_S_B_DIR), $(SRC_S_B:.c=.o))
DEP_S_B = $(addsuffix .d, $(basename $(OBJ_S_B)))
# ========================

# ----OBJ y DEP Client----
OBJ_C = $(addprefix $(OBJ_C_DIR), $(SRC_C:.c=.o))
DEP_C = $(addsuffix .d, $(basename $(OBJ_C)))

OBJ_C_B = $(addprefix $(OBJ_C_B_DIR), $(SRC_C_B:.c=.o))
DEP_C_B = $(addsuffix .d, $(basename $(OBJ_C_B)))
# ========================


$(OBJ_S_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

$(OBJ_C_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

$(OBJ_S_B_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

$(OBJ_C_B_DIR)%.o: %.c $(MKFL)
	@$(MP) $(dir $@)
	${CC} $(CFLAGS) -MMD -I ./ -c $< -o $@

all:
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(PRINTFDIR)
	@$(MAKE) $(CLI)
	@$(MAKE) $(SRV)

bonus: all
	@$(MAKE) $(CLI_BONUS)
	@$(MAKE) $(SRV_BONUS)	

$(SRV): $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) $(LFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a -o $(SRV)

$(SRV_BONUS): $(OBJ_S_B)
	$(CC) $(CFLAGS) $(OBJ_S_B) $(LFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a -o $(SRV_BONUS)

$(CLI): $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) $(LFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a -o $(CLI)

$(CLI_BONUS): $(OBJ_C_B)
	$(CC) $(CFLAGS) $(OBJ_C_B) $(LFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a -o $(CLI_BONUS)

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LFTDIR)
	@$(MAKE) clean -C $(PRINTFDIR)
	$(RM) $(OBJ_S_DIR) $(OBJ_C_DIR)
	$(RM) $(OBJ_S_B_DIR) $(OBJ_C_B_DIR)

fclean:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LFTDIR)
	@$(MAKE) fclean -C $(PRINTFDIR)
	$(RM) $(SRV) $(CLI)
	$(RM) $(SRV_BONUS) $(CLI_BONUS)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
