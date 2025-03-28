### COLORS ###
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

### VARIABLES ###

NAME = animals00
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJF = .cache_exists	# needed to create obj/ directory
.DEFAULT_GOAL := all	# make = make all
update_flag := false

# Directories
OBJ_DIR = obj/

# Source Files
SRC_FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

# Object Files
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

### COMPILATION ###

$(OBJF):
	@mkdir -p $(OBJ_DIR)

# Creating object files (.o) from source files (.c) inside the OBJ_DIR directory.
# The option -o indicates the name of the outpout, the option -c indicates the source that is used.

$(OBJ_DIR)%.o : %.cpp | $(OBJF)
	@echo "$(YELLOW)Compiling $<...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Compiling all objets files (.o) to a file "NAME" :
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)>>> $(NAME) compiled!$(DEF_COLOR)"
	@$(eval update_flag := true)

### MEMO ###
# 	Special variables :
#		$@	Represents the target file that is being generated by the rule
#		$<	Represents the first dependency of the rule
#		$^	Represents all the dependencies of the rule, separated by spaces.
#		$?	Represents a list of dependencies that are newer than the target file.
#		$*	Represents the stem of the target filename (without the extension)

### RULES ###

nothing_to_be_done:
	@if [ "$(update_flag)" = "false" ]; then \
		echo "$(GREEN)>>> make: Nothing to be done for 'all'.$(DEF_COLOR)"; \
	fi

all : $(NAME) nothing_to_be_done

# Flag to check if 'clean' is executed alone or as a dependency of 'fclean'
fclean_flag := false
do_fclean:
	@$(eval fclean_flag := true)

clean :
	@echo "$(YELLOW)Cleaning $(NAME)... $(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@if [ "$(fclean_flag)" = "false" ]; then \
		echo "$(GREEN)>>> $(NAME) object files cleaned!$(DEF_COLOR)"; \
fi
	@if [ "$(fclean_flag)" = "true" ]; then \
		echo "$(GREEN)>>> $(NAME) object files & executables cleaned!$(DEF_COLOR)"; \
fi

fclean : do_fclean clean
	@rm -f $(NAME)

re :	fclean all
	@echo "$(CYAN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

# Phony targets are used to differenciate makefile rules from system files.
.PHONY: all clean fclean re nothing_to_be_done do_fclean