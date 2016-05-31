#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/10 16:54:54 by kpiacent          #+#    #+#              #
#    Updated: 2016/05/24 09:36:57 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = ft_select
L_DIR = libft/
F_DIR = src/
H_DIR = ./includes
FILES = main.c term.c arg.c arglist.c
FILES_PATH = $(addprefix $(F_DIR), $(FILES))

TMP = Makefile~  $(F_DIR)/$(NAME).h~ $(NAME)~ $(FILES_PATH:.c=.c~)

all : $(NAME)

$(NAME) :
		@cd $(L_DIR) && $(MAKE)
		@CC -o $(NAME) $(FLAGS) $(FILES_PATH) -I $(H_DIR) -L $(L_DIR) -lft -lncurses
		@echo "Complilation: \t\t\tDONE!"

clean :
		@rm -f $(TMP)
		@cd $(L_DIR) && $(MAKE) $@
		@echo "Cleaning: \t\t\tDONE!"

fclean : clean
		@rm -f $(NAME)
		@cd $(L_DIR) && $(MAKE) $@
		@echo "Remove the exec: \t\tDONE!"
test :
	./$(NAME)

re : fclean all
