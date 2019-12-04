CC=g++
CFLAGS=-Wall

all: rpn

rpn: calculator.cpp operations.cpp helpers.cpp
	$(CC) $(CFLAGS) -o rpn  calculator.cpp operations.cpp helpers.cpp

test: operations.cpp helpers.cpp test/tests.cpp test/operations.cpp test/helpers.cpp
	$(CC) $(CFLAGS) -o testall operations.cpp helpers.cpp test/tests.cpp test/operations.cpp test/helpers.cpp

clean:
	rm -f rpn
	rm -f testall

install: rpn
	cp -f rpn /usr/local/bin/rpn
