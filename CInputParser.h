#ifndef CInputParser_h
#define CInputParser_h

#include <algorithm>

#include <string>

#include <vector>

#include <iostream>     // std::cout, std::ostream, std::ios
#include <sstream>


using std::string;
using std::iostream;

class CInputParser
{
  public:
    CInputParser (int &argc, char **argv);

    CInputParser (void);

    const std::string& getCmdOption (const std::string &option) const;

    bool cmdOptionExists (const std::string &option) const;

    void listCmdOptions (void) const;

  private:
    std::vector <std::string> tokens;
};

#endif
