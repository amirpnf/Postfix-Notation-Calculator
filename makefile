CC = gcc
CFLAGS =-std=c17 -pedantic -Wall
LDFLAGS = -lreadline -lm
OBJ_DIR= obj/
OBJ = ${OBJ_DIR}stack.o ${OBJ_DIR}lines.o ${OBJ_DIR}operations.o
EXE = bin/test
REG = src/

all : $(EXE)

$(EXE): $(REG)main.c $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	

stack.o: $(REG)stack.c $(REG)stack.h 

lines.o: $(REG)lines.c $(REG)lines.h $(REG)operations.h

operations.o : $(REG)operations.c $(REG)operations.h


${OBJ_DIR}%.o: $(REG)%.c
	mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f obj/*

mrproper: clean
	rm -f $(EXE)
	rm -f $(TEST)