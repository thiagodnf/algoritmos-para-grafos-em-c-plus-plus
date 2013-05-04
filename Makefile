# Universidade Estadual do Ceara
# Mestrado Academico em Ciencia da Computacao
# Projeto de Analise de Algoritmo - 2013.1
# By Thiago Nascimento

CC = g++
SRC.DIR = src
OBJ.DIR = obj
BIN.DIR = bin
FLAGS = -W -Wall -ansi -pedantic
EXEC = paa
CPP_FILES := $(wildcard $(SRC.DIR)/*.cpp)
OBJ_FILES := $(addprefix $(OBJ.DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

$(EXEC): $(OBJ_FILES)
	@mkdir -p $(BIN.DIR)
	$(CC) $(FLAGS) -o $(BIN.DIR)/$@ $^
	
obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN.DIR)/$(EXEC)
	rm -rf $(OBJ.DIR)/*.o