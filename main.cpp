#include "EventManager.h"
#include "CInputParser.h"
#include "CCommandParser.h"
#include "main.h"


A::A1::A1()
{
  // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
  EventManager *myEventManager = EventManager::Instance();

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

};

A::A()
{
  // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
  EventManager *myEventManager = EventManager::Instance();
  printf ("createEvent(testEvent-CCommandParser)\n");
  myEventManager->createEvent ("testEvent-CCommandParser");
}

void A::fireEvents()
{
  // Fire the event and all the subscribed class methods will get called.
  EventManager *myEventManager = EventManager::Instance();

  myEventManager->execute ("exit");
  myEventManager->execute ("help");
  myEventManager->execute ("list");
  myEventManager->execute ("dataitems");
  myEventManager->execute ("request");
  myEventManager->execute ("elements");
}


void CCommandParser::COptionOne::listenerCOptionOne()
{
  printf ("Listener of COptionOne called\n");
}

void CCommandParser::COptionOne::Add()
{
  // When testEvent is called the listener method of this class will get called.
  EventManager *myEventManager = EventManager::Instance();

  printf ("subscribe(testEvent-COptionOne)\n");
  myEventManager->subscribe ("testEvent-COptionOne", this, &CCommandParser::COptionOne::listenerCOptionOne);
}


void CCommandParser::COptionTwo::listenerCOptionTwo()
{
  printf ("Listener of COptionTwo called\n");
}

void CCommandParser::COptionTwo::Add()
{
  // When testEvent is called the listener method of this class will get called.
  EventManager *myEventManager = EventManager::Instance();

  printf ("subscribe(testEvent-COptionTwo)\n");
  myEventManager->subscribe ("testEvent-COptionTwo", this, &CCommandParser::COptionTwo::listenerCOptionTwo);
}


int main()
{
  A *obj0 = new A;
  CCommandParser *pCommandParser = new CCommandParser;

  pCommandParser->AddOptions();
  obj0->fireEvents();

  while (true)
  {
    CInputParser input;

    if (input.cmdOptionExists ("-h") || input.cmdOptionExists ("help") )
    {
      // Do stuff
      std::cout << "list dataitems [-F <filter string>]" << std::endl;
      std::cout << "list elements -D <data item>" << std::endl;
      std::cout << "request <data item> -e <element name> -v <value>" << std::endl;

      return -1;
    }

    if (input.cmdOptionExists ("exit") )
    {
      return 0;
    }
  }

  return 0;
}
