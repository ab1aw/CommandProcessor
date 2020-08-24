#include "CEventManager.h"
#include "CInputParser.h"
#include "CMyCommandParser.h"
#include "main.h"


A::A1::A1()
{
  myEventManager = CEventManager::Instance();

  printf ("createEvent(exit)\n");
  myEventManager->createEvent ("exit");

  printf ("createEvent(help)\n");
  myEventManager->createEvent ("help");

  printf ("createEvent(list)\n");
  myEventManager->createEvent ("list");

  printf ("createEvent(dataitems)\n");
  myEventManager->createEvent ("dataitems");

  printf ("createEvent(request)\n");
  myEventManager->createEvent ("request");

  printf ("createEvent(elements)\n");
  myEventManager->createEvent ("elements");

  printf ("createEvent(-F)\n");
  myEventManager->createEvent ("-F");

  printf ("createEvent(-D)\n");
  myEventManager->createEvent ("-D");

  printf ("createEvent(-F)\n");
  myEventManager->createEvent ("-V");

};

A::A()
{
  myEventManager = CEventManager::Instance();

  printf ("createEvent(testEvent-CMyCommandParser)\n");
  myEventManager->createEvent ("testEvent-CMyCommandParser");
}

void A::fireEvents()
{
  std::string parameter = "argument one";
  myEventManager->execute ("exit", parameter);

  parameter = "argument two";
  myEventManager->execute ("help", parameter);

  parameter = "argument seven";
  myEventManager->execute ("-F", parameter);

  parameter = "argument eight";
  myEventManager->execute ("-D", parameter);

  parameter = "argument nine";
  myEventManager->execute ("-V", parameter);

  parameter = "argument four";
  myEventManager->execute ("dataitems", parameter);

  parameter = "argument six";
  myEventManager->execute ("elements", parameter);

  parameter = "argument three";
  myEventManager->execute ("list", parameter);

  parameter = "argument five";
  myEventManager->execute ("request", parameter);
}


int main()
{
  A *obj0 = new A;
  CMyCommandParser *pCommandParser = new CMyCommandParser;

  pCommandParser->AddOptions();
  obj0->fireEvents();

  while (true)
  {
    CInputParser input;

    input.listCmdOptions();

    if (input.cmdOptionExists ("-h") || input.cmdOptionExists ("help") )
    {
      // Do stuff
      std::cout << "\tlist dataitems [-F <filter string>]" << std::endl;
      std::cout << "\tlist elements -D <data item> [-V]" << std::endl;
      std::cout << "\trequest <data item> -e <element name> -v <value>" << std::endl;

      continue;
    }

    if (input.cmdOptionExists ("exit") )
    {
      return 0;
    }
  }

  return 0;
}
