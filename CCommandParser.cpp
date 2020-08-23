#include "EventManager.h"
#include "CCommandParser.h"
#include "main.h"


void CCommandParser::Exit (std::string &arg)
{
  printf ("CCommandParser Exit invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::Help (std::string &arg)
{
  printf ("CCommandParser Help invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::List (std::string &arg)
{
  printf ("CCommandParser List invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::DataItems (std::string &arg)
{
  printf ("CCommandParser DataItems invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::Request (std::string &arg)
{
  printf ("CCommandParser Request invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::Elements (std::string &arg)
{
  printf ("CCommandParser Elements invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CCommandParser::AddOptions (void)
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
