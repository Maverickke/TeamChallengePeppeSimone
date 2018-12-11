CC= D:\Programmi\LLVM\bin\clang.exe
CPPCHECK= D:\Programmi\Cppcheck\cppcheck.exe
CFLAGS= -Wall -Werror-Wdeprecated-declarations -O3 -Wno-pragma-pack -ID:\simon\Documents\ProjectVisual\TeamChallengePeppeSimone\TeamChallengePeppeSimone\SDL2-2.0.9\include
LDFLAGS= -lSDL2 -LD:\simon\Documents\ProjectVisual\TeamChallengePeppeSimone\TeamChallengePeppeSimone
BINARY= main
BINARY_TESTS= main_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

main: main.o 
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^