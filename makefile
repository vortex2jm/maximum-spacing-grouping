EXECUTABLE       = trab1
SRC              = ./src
INCLUDE          = ./include
OBJ              = ./obj
FLAGS            = -lm -pedantic -Wall -g
ADD_FLAGS        = -Wextra -O2
COMPILER         = gcc   

# Path and extesions
C_FILES        = $(wildcard $(SRC)/*.c | $(SRC)/**/*.c)
OBJ_PATH_FILES = $(patsubst $(SRC)%,$(OBJ)%,$(C_FILES))
OBJ_FILES      = $(patsubst %.c,%.o,$(OBJ_PATH_FILES))

# Colors
YELLOW = "\033[1;33m"
RED = "\033[1;31m" 
CYAN = "\033[1;36m"
PURPLE = "\033[1;35m"
RESET_COLOR = "\033[0m"

#===========================================================#
# Main target
all: clean create_dir $(OBJ_FILES) $(EXECUTABLE)

# Creatig objects directory
create_dir: 
# @ echo $(PURPLE)
# @ echo "Creating $(OBJ) directory...\n"
	@ mkdir $(OBJ)
# @ echo $(RESET_COLOR)

# Compiling cpp files
$(OBJ)/%.o: $(SRC)/%.c 
# @ echo $(YELLOW)
# @ echo "Compiling file $<..."
	@ $(COMPILER) -c $< -o $@
# @ echo $(RESET_COLOR)

# Creating executable
$(EXECUTABLE): 
# @ echo $(YELLOW)
# @ echo "Creating executable..."
	@ $(COMPILER) $< $(OBJ)/*.o -o $@ $(FLAGS)
# @ echo $(RESET_COLOR)

# Cleaning workspace
clean:
# @ echo $(RED)
# @ echo "Cleaning workspace..."
	@ rm -rf $(OBJ) $(EXECUTABLE) *.txt
# @ echo $(RESET_COLOR)

run:
	@ ./trab1 test/in/1.txt 2 out1.txt
	@ ./trab1 test/in/2.txt 4 out2.txt
	@ ./trab1 test/in/3.txt 5 out3.txt
	@ ./trab1 test/in/4.txt 5 out4.txt
	@ ./trab1 test/in/5.txt 10 out5.txt

diff:
	@ diff out1.txt test/out/1.txt
	@ diff out2.txt test/out/2.txt
	@ diff out3.txt test/out/3.txt
	@ diff out4.txt test/out/4.txt
	@ diff out5.txt test/out/5.txt	
