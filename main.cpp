#include "EventManager.h"
#include "main.h"


A::A1::A1()
{
  // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
  EventManager *myEventManager = EventManager::Instance();

  printf ("createEvent(testEvent-COptionOne)\n");
  myEventManager->createEvent ("testEvent-COptionOne");

  printf ("createEvent(testEvent-COptionTwo)\n");
  myEventManager->createEvent ("testEvent-COptionTwo");
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
  myEventManager->execute ("testEvent-COptionOne");
  myEventManager->execute ("testEvent-COptionTwo");
  myEventManager->execute ("testEvent-CCommandParser");
}


void CCommandParser::COptionOne::listenerCOptionOne()
{
  printf ("Listener of COptionOne called\n");
};

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
};

void CCommandParser::COptionTwo::Add()
{
  // When testEvent is called the listener method of this class will get called.
  EventManager *myEventManager = EventManager::Instance();

  printf ("subscribe(testEvent-COptionTwo)\n");
  myEventManager->subscribe ("testEvent-COptionTwo", this, &CCommandParser::COptionTwo::listenerCOptionTwo);
}


void CCommandParser::listenerCCommandParser()
{
  printf ("Listener of CCommandParser called\n");
}

void CCommandParser::AddOptions()
{
  MyCOptionOne.Add();
  MyCOptionTwo.Add();
}

CCommandParser::CCommandParser()
{
  // When testEvent is called the listener method of this class will get called.
  EventManager *myEventManager = EventManager::Instance();

  printf ("subscribe(testEvent-CCommandParser)\n");
  myEventManager->subscribe ("testEvent-CCommandParser", this, &CCommandParser::listenerCCommandParser);
}


int main()
{
  A *obj0 = new A;
  CCommandParser *pCommandParser = new CCommandParser;

  pCommandParser->AddOptions();
  obj0->fireEvents();

  return 0;
}
