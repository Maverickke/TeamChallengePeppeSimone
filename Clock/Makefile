CC=clang
CFLAGS=-Wall -Werror -O3 -Wno-pragma-pack -I D:\Users\Peppe\Documents\Lesson_C\Tetris\SDL2-2.0.9\include   #attiva tutti i controlli del compilatore, Werror -> trasforma tutti i warning in errore. -O3 ottimizzazione al messimo.
LDFLAGS=-lSDL2 -L.

all: clock.exe  #scorciatoia perche se non gli passi alcun argomenti si va a cerca tutti quelli che si chiamano all

clock.exe: main.o 
	$(CC) $(LDFLAGS) -o $@ $^ 

main.o:	main.c
	$(CC) $(CFLAGS) -c -o $@ $^