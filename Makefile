# Universidade Estadual do Ceara
# Mestrado Academico em Ciencia da Computacao
# Projeto de Analise de Algoritmo - 2013.1
# Equipe
# 	Robert Marinho
# 	Thiago Nascimento

SRC.DIR = src
FLAGS = -W -Wall -ansi -pedantic
EXEC = paa


all: compile

compile:
	g++ $(FLAGS) -o $(EXEC) $(SRC.DIR)/main.cpp

clean:
	rm -rf $(EXEC)