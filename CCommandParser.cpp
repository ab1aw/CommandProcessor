#include "EventManager.h"
#include "CCommandParser.h"
#include "main.h"


void CCommandParser::Exit()
{
  printf ("CCommandParser Exit invoked\n");
}

void CCommandParser::Help()
{
  printf ("CCommandParser Help invoked\n");
}

void CCommandParser::List()
{
  printf ("CCommandParser List invoked\n");
}

void CCommandParser::DataItems()
{
  printf ("CCommandParser DataItems invoked\n");
}

void CCommandParser::Request()
{
  printf ("CCommandParser Request invoked\n");
}

void CCommandParser::Elements()
{
  printf ("CCommandParser Elements invoked\n");
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

  myEventManager->subscribe ("exit", this, &CCommandParser::Exit);
  myEventManager->subscribe ("help", this, &CCommandParser::Help);
  myEventManager->subscribe ("list", this, &CCommandParser::List);
  myEventManager->subscribe ("dataitems", this, &CCommandParser::DataItems);
  myEventManager->subscribe ("request", this, &CCommandParser::Request);
  myEventManager->subscribe ("elements", this, &CCommandParser::Elements);
}
