all : main.exe

main.exe : main.cpp main.h  CEventManager.cpp CEventManager.h CCommandParser.cpp CCommandParser.h CInputParser.cpp CInputParser.h CMyCommandParser.cpp CMyCommandParser.h
	g++ -ggdb -Wall -Werror -o main.exe main.cpp CEventManager.cpp CCommandParser.cpp CInputParser.cpp CMyCommandParser.cpp


run : main.exe
	./main.exe


clean :
	rm -f main.exe