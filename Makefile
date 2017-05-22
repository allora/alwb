BIN=alwb
BUILDDIR=build
SRC=$(wildcard src/*.cc)
INCL=$(wildcard src/*.h)
OBJ=${SRC:.cc=.o}

CC=g++
CFLAGS=-c -Wall -std=c++11 `pkg-config gtkmm-3.0 --cflags` `pkg-config webkit2gtk-4.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs` `pkg-config webkit2gtk-4.0 --libs`

.POSIX:
all: clean ${BIN}

${BIN}: ${OBJ}
	${CC} ${LDFLAGS} ${OBJ} -o $@

.cc.o: ${SRC} ${INCL}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -f ${BIN} ${OBJ}

install:
	cp alwm /usr/local/bin/
