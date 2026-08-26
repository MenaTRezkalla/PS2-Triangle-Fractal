CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

.PHONY: all clean lint

all: Triangle

%.o: %.cpp triangle.hpp
	$(CC) $(CFLAGS) -c $<

Triangle: main.o triangle.o
	$(CC) $(CFLAGS) -o Triangle main.o triangle.o $(LIB)

clean:
	rm *.o Triangle

lint:
	cpplint *.cpp *.hpp