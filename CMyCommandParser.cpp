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
  printf ("CMyCommandParser List invoked w/ arg <%s> using%sfilter %s\n\n", arg.c_str(), ((MyOptionOne.DataItemFilter.empty()) ? " no " : " "), MyOptionOne.DataItemFilter.c_str() );
  MyOptionOne.DataItemFilter = "";
}

void CMyCommandParser::DataItems (std::string &arg)
{
  printf ("CMyCommandParser DataItems invoked w/ arg <%s> using%sfilter %s\n\n", arg.c_str(), ((MyOptionOne.DataItemFilter.empty()) ? " no " : " "), MyOptionOne.DataItemFilter.c_str() );
}

void CMyCommandParser::Request (std::string &arg)
{
  printf ("CMyCommandParser Request invoked w/ arg <%s>\n\n", arg.c_str() );
}

void CMyCommandParser::Elements (std::string &arg)
{
  printf ("CMyCommandParser Elements invoked w/ arg <%s> and verbosity %s\n\n", arg.c_str(), ((MyOptionThree.Verbose) ? "on" : "off") );
  MyOptionThree.Verbose = false;
}

void CMyCommandParser::AddOptions (void)
{
  MyOptionOne.Add();
  MyOptionTwo.Add();
  MyOptionThree.Add();
}

CMyCommandParser::CMyCommandParser()
{
  // When testEvent is called the listener method of this class will get called.
  myEventManager = CEventManager::Instance();

  myEventManager->subscribe ("exit", this, &CMyCommandParser::Exit);
  myEventManager->subscribe ("help", this, &CMyCommandParser::Help);
  myEventManager->subscribe ("list", this, &CMyCommandParser::List);
  myEventManager->subscribe ("dataitems", this, &CMyCommandParser::DataItems);
  myEventManager->subscribe ("request", this, &CMyCommandParser::Request);
  myEventManager->subscribe ("elements", this, &CMyCommandParser::Elements);
}


void CMyCommandParser::COptionOne::listenerCOptionOne (std::string &arg)
{
  printf ("Listener of -F called w/ arg: <%s>\n\n", arg.c_str() );
  DataItemFilter = arg;
}

void CMyCommandParser::COptionOne::Add()
{
  printf ("subscribe(-F)\n");
  myEventManager->subscribe ("-F", this, &CMyCommandParser::COptionOne::listenerCOptionOne);
  
  // Set initial (default) value.
  DataItemFilter = "";
}


void CMyCommandParser::COptionTwo::listenerCOptionTwo (std::string &arg)
{
  printf ("Listener of -D called w/ arg: <%s>\n\n", arg.c_str() );
  DataItem = arg;
}

void CMyCommandParser::COptionTwo::Add()
{
  printf ("subscribe(-D)\n");
  myEventManager->subscribe ("-D", this, &CMyCommandParser::COptionTwo::listenerCOptionTwo);
  
  // Set initial (default) value.
  DataItem = "";
}


void CMyCommandParser::COptionThree::listenerCOptionThree (std::string &arg)
{
  printf ("Listener of -V called w/ arg: <%s>\n\n", arg.c_str() );
  Verbose = true;
}

void CMyCommandParser::COptionThree::Add()
{
  printf ("subscribe(-V)\n");
  myEventManager->subscribe ("-V", this, &CMyCommandParser::COptionThree::listenerCOptionThree);
  
  // Set initial (default) value.
  Verbose = false;
}
