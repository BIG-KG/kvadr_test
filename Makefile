# DEBUG_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: hello2
	
hello2: main.o equ_new.o entering.o
	g++ main.o equ_new.o entering.o -o hello2.exe
	

main.o: main.c
	g++ -c $(DEBUG_FLAGS) main.c
equ_new.o: equ_new.c
	g++ -c $(DEBUG_FLAGS) equ_new.c

entering.o: entering.c
	g++ -c $(DEBUG_FLAGS) entering.c

clean:
	rm -rf *.o hello2