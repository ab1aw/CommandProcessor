
#include "CInputParser.h"
#include "EventManager.h"



CInputParser::CInputParser (int &argc, char **argv)
{
  this->tokens.clear();

  for (int i = 1; i < argc; ++i)
  {
    this->tokens.push_back (std::string (argv[i]) );
  }
}


CInputParser::CInputParser (void)
{
  this->tokens.clear();

  std::string aline;
  std::getline (std::cin, aline);
  std::string firstName, middleName, lastName;

  std::istringstream iss (aline);

  while ( ! iss.eof() )
  {
    iss >> firstName;
    std::cout << "Pushback " << firstName << " length " << firstName.size() << std::endl;
    this->tokens.push_back (firstName);
  }

#if 0
  std::string b;
  std::cin >> b;

  while (std::cin)
  {
    std::cout << "Pushback " << b << " length " << b.size() << std::endl;
    this->tokens.push_back (b);
    std::cin >> b;
  }

#endif

  std::cout << "DONE" << std::endl;
}

const std::string& CInputParser::getCmdOption (const std::string &option) const
{
  std::vector<std::string>::const_iterator itr;
  itr =  std::find (this->tokens.begin(), this->tokens.end(), option);

  if (itr != this->tokens.end() && ++itr != this->tokens.end() )
  {
    return *itr;
  }

  static const std::string empty_string ("");
  return empty_string;
}

bool CInputParser::cmdOptionExists (const std::string &option) const
{
  return std::find (this->tokens.begin(), this->tokens.end(), option)
         != this->tokens.end();
}


void CInputParser::listCmdOptions (void) const
{
  std::vector<std::string>::const_iterator itr;

  std::cout << "void CInputParser::listCmdOptions (void) const" << std::endl;

  for (itr = this->tokens.begin(), itr++; itr != this->tokens.end(); itr++)
  {
    std::cout << "Attempt to execute: " << *itr << std::endl;

    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    
    std::string parameter = "some argument";
    myEventManager->execute (*itr, parameter);
  }
}
