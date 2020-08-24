#include "CEventManager.h"
#include "CMyCommandParser.h"
#include "main.h"


void CMyCommandParser::Exit (std::string &arg)
{
  printf ("CMyCommandParser Exit invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::Help (std::string &arg)
{
  printf ("CMyCommandParser Help invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::List (std::string &arg)
{
  printf ("CMyCommandParser List invoked w/ arg <%s> using filter %s\n\n", arg.c_str(), MyCOptionOne.DataItemFilter.c_str() );
}

void CMyCommandParser::DataItems (std::string &arg)
{
  printf ("CMyCommandParser DataItems invoked w/ arg <%s> using filter %s\n\n", arg.c_str(), MyCOptionOne.DataItemFilter.c_str() );
}

void CMyCommandParser::Request (std::string &arg)
{
  printf ("CMyCommandParser Request invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::Elements (std::string &arg)
{
  printf ("CMyCommandParser Elements invoked w/ arg <%s> and verbosity %s\n\n", arg.c_str(), ((MyCOptionTwo.Verbose) ? "on" : "off") );
}

void CMyCommandParser::AddOptions (void)
{
  MyCOptionOne.Add();
  MyCOptionTwo.Add();
}

CMyCommandParser::CMyCommandParser()
{
  // When testEvent is called the listener method of this class will get called.
  CEventManager *myEventManager = CEventManager::Instance();

  myEventManager->subscribe ("exit", this, &CMyCommandParser::Exit);
  myEventManager->subscribe ("help", this, &CMyCommandParser::Help);
  myEventManager->subscribe ("list", this, &CMyCommandParser::List);
  myEventManager->subscribe ("dataitems", this, &CMyCommandParser::DataItems);
  myEventManager->subscribe ("request", this, &CMyCommandParser::Request);
  myEventManager->subscribe ("elements", this, &CMyCommandParser::Elements);
}


void CMyCommandParser::COptionOne::listenerCOptionOne (std::string &arg)
{
  DataItemFilter = arg;
  printf ("Listener of -F called w/ arg: <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::COptionOne::Add()
{
  // When testEvent is called the listener method of this class will get called.
  CEventManager *myEventManager = CEventManager::Instance();

  printf ("subscribe(-F)\n");
  myEventManager->subscribe ("-F", this, &CMyCommandParser::COptionOne::listenerCOptionOne);
}


void CMyCommandParser::COptionTwo::listenerCOptionTwo (std::string &arg)
{
  Verbose = true;
  printf ("Listener of -D called w/ arg: <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::COptionTwo::Add()
{
  // When testEvent is called the listener method of this class will get called.
  CEventManager *myEventManager = CEventManager::Instance();

  printf ("subscribe(-D)\n");
  myEventManager->subscribe ("-D", this, &CMyCommandParser::COptionTwo::listenerCOptionTwo);
}
