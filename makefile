CC = clang
CFLAGS =-std=c17 -pedantic -Wall
LDFLAGS = -lreadline -lm
OBJ_DIR= obj/
OBJ = ${OBJ_DIR}stack.o ${OBJ_DIR}readline.o
EXE = bin/test
REG = src/

all : $(EXE)

$(EXE): $(REG)main.c $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	

stack.o: $(REG)stack.c $(REG)stack.h 

readline.o: $(REG)readline.c $(REG)readline.h 


${OBJ_DIR}%.o: $(REG)%.c
	mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f obj/*

mrproper: clean
	rm -f $(EXE)
	rm -f $(TEST)