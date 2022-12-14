CC=g++

CFLAGS+=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJ+=main.o initializers_and_destructors.o bufferize.o get_size.o read_text.o comps.o fputLine.o my_sort.o separateLines.o cntLines.o handleComLine.o

all: Hamlet.exe

Hamlet.exe: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o Hamlet.exe

*.o: *.cpp
	$(CC) $(CFLAGS) *.cpp -c

clean:
	rm -rf *.o *.exe*
	clear

run:
	make
	clear
	./Hamlet.exe Hamlet HamletStraight HamletArab Hamletdefault

.PHONY: clean run