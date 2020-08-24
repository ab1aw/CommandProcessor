all : main.exe

main.exe : main.cpp main.h  EventManager.cpp EventManager.h CCommandParser.cpp CCommandParser.h CInputParser.cpp CInputParser.h CMyCommandParser.cpp CMyCommandParser.h
	g++ -ggdb -Wall -Werror -o main.exe main.cpp EventManager.cpp CCommandParser.cpp CInputParser.cpp CMyCommandParser.cpp


run : main.exe
	./main.exe


clean :
	rm -f main.exe