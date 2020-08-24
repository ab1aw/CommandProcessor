
#ifndef CCommandParser_h
#define CCommandParser_h

#include "CEventManager.h"


class CCommandParser
{
  public:

    class CGenericOption
    {
      public:
        CGenericOption() {};
        virtual ~CGenericOption() {};
        virtual void Add() = 0;
    };

    virtual void Exit (std::string &arg) = 0;
    virtual void Help (std::string &arg) = 0;

    virtual void AddOptions (void) = 0;

    CCommandParser() {};
    virtual ~CCommandParser() {};
};

#endif
