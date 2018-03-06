all: calculator

calculator: Calculator.cpp operations.cpp explode.cpp valid.cpp
	g++ Calculator.cpp operations.cpp explode.cpp valid.cpp

clean:
	rm -f a.out
