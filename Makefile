PROJECT = "C_GAME"
CC = gcc
CFLAGS = -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/include/SDL -I/usr/include/SDL2 -lSDL -lSDL2_image -lSDL2
SOURCES = $(wildcard src/*.c)

main: $(SOURCES)
	${CC} ${SOURCES} ${CFLAGS} -o build/${PROJECT}

run:
	./build/${PROJECT}

clean:
	rm build/${PROJECT}
