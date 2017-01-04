
target : funix.out

funix.o : funix.cpp
	g++ -Wall -g -ansi funix.cpp -c

main.o : main.cpp
	g++ -Wall -g -ansi main.cpp -c

permissions.o : permissions.cpp
	g++ -Wall -g -ansi permissions.cpp -c

directory.o : directory.cpp
	g++ -Wall -g -ansi directory.cpp -c

funix.out : funix.o main.o permissions.o directory.o
	g++ -Wall -g -ansi funix.o main.o permissions.o directory.o -o funix.out

clean :
	rm -f ./*.o
	rm -f ./funix.out
