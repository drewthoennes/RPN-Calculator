all: calculator

calculator: handler.cpp Calculator.cpp operations.cpp explode.cpp valid.cpp
	g++ -o rpn  handler.cpp Calculator.cpp operations.cpp explode.cpp valid.cpp

tests: operations.cpp explode.cpp valid.cpp test/tests.cpp test/Calculator.cpp test/operations.cpp test/explode.cpp test/valid.cpp
	g++ -o testall Calculator.cpp operations.cpp explode.cpp valid.cpp test/tests.cpp test/Calculator.cpp test/operations.cpp test/explode.cpp test/valid.cpp

clean:
	rm -f rpn
	rm -f testall

install:
	cp -f rpn /usr/local/bin/rpn
