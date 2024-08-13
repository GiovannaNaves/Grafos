CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/grafo.o
HDRS = $(INC)/grafo.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(SRC)/main.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/grafo.o: $(SRC)/grafo.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp

clean:
	rm -f $(EXE) $(OBJS)
