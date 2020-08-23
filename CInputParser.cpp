
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
    std::cout << *itr << std::endl;

    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->execute (*itr);
  }
}


#if 0
int main (int argc, char **argv)
{
//  CInputParser input (argc, argv);

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

    // list dataitems [-F <filter string>]
    // list elements -D <data item>
    const std::string &list_sub_cmd = input.getCmdOption ("list");

    if (!list_sub_cmd.empty() )
    {
      if ( list_sub_cmd == "dataitems" )
      {
        // Do interesting things ...

        const std::string &filter = input.getCmdOption ("-F");

        if (!filter.empty() )
        {
          // Do interesting things ...
          std::cout << "list all data items filtering with <" << filter << ">." << std::endl;
          continue;
        }
        else
        {
          std::cout << "list all data items without using a filter." << std::endl;
          continue;
        }
      }

      else if ( list_sub_cmd == "elements" )
      {
        // Do interesting things ...

        const std::string &data_item = input.getCmdOption ("-D");

        if (!data_item.empty() )
        {
          // Do interesting things ...
          std::cout << "list all elements owned by data item: <" << data_item << ">." << std::endl;
          continue;
        }
        else
        {
          std::cerr << "missing data item name." << std::endl;
          continue;
        }
      }
    }
    else if ( input.cmdOptionExists ("list") )
    {
      std::cerr << "missing list arguments." << std::endl;
      continue;
    }


    // request <data item> -e <element name> -v <value>
    const std::string &request_sub_cmd = input.getCmdOption ("request");

    if (!request_sub_cmd.empty() )
    {
      // Do interesting things ...

      const std::string &element = input.getCmdOption ("-e");
      const std::string &value = input.getCmdOption ("-v");

      if (!element.empty() && !value.empty() )

      {
        std::cout << "request new value <" << value << "> for data item <" << request_sub_cmd << "> element <" << element << ">." << std::endl;
        continue;
      }
      else
      {
        std::cerr << "missing data item element or value (or both)." << std::endl;
        continue;
      }
    }
    else if ( input.cmdOptionExists ("request") )
    {
      std::cerr << "missing request arguments." << std::endl;
      continue;
    }






    const std::string &filename = input.getCmdOption ("-f");

    if (!filename.empty() )
    {
      // Do interesting things ...
      std::cout << "Got a -f " << filename << " option." << std::endl;
      continue;
    }

    std::cerr << "missing command arguments." << std::endl;
  }

  return 0;
}
#endif
