all : main.exe

main.exe : main.cpp main.h  EventManager.cpp EventManager.h
	g++ -ggdb -Wall -Werror -o main.exe main.cpp EventManager.cpp


run : main.exe
	./main.exe


clean :
	rm -f main.exe