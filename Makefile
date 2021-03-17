# Variables
OBJ = date.o sessionlist.o tracker.o
OBJ1 = datetest.o date.o sessionlist.o
OBJ2 = sesionlisttest.o sessionlist.o date.o 
CFLAGS = -Wall -pedantic

#Operativ System dependent variables
ifeq ($(OS), Windows_NT)
RM = del
BIN = tracker.exe datetest.exe sesionlisttest.exe
else 
RM = rm
BIN = tracker datetest sesionlisttest
endif

# Targets
#%.o: %.c
#	gcc $(CFLAGS) -c $< -o $@

datee.o: datee.c datee.h
	gcc $(CFLAGS) -c datee.c -o datee.o 

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

sessionlist.o: sessionlist.c  sesionlist.h date.h debug.h
	gcc $(CFLAGS) -c sessionlist.c -o sessionlist.o

tracker.o: tracker.c date.h sesionlist.h debug.h
	gcc $(CFLAGS) -c tracker.c -o tracker.o	

tracker: date.o sessionlist.o tracker.o	
	gcc $(CFLAGS) $(OBJ) -o tracker

all: tracker datetest sesionlisttest

clean:
	$(RM) $(BIN) $(OBJ) $(OBJ1) $(OBJ2)

# ========================
# MY TARGET TESTS 
# ========================

datetest.o: datetest.c date.h
	gcc $(CFLAGS) -c datetest.c -o datetest.o

datetest: datetest.o date.o sessionlist.o
	gcc $(CFLAGS) $(OBJ1) -o datetest	

sesionlisttest.o: sesionlisttest.c sesionlist.h
	gcc $(CFLAGS) -c sesionlisttest.c -o sesionlisttest.o


sesionlisttest: sesionlisttest.o date.o sessionlist.o
	gcc $(CFLAGS) $(OBJ2) -o sesionlisttest

test: datetest sesionlisttest
		
runtest: datetest sesionlisttest
	./datetest.exe
	./sesionlisttest.exe

.DEFAULT_GOAL := all