
#ifndef CCommandParser_h
#define CCommandParser_h

#include "CEventManager.h"


class CCommandParser
{
  public:

    class CGenericOption
    {
      public:
        CGenericOption() { myEventManager = CEventManager::Instance(); };
        virtual ~CGenericOption() {};
        virtual void Add() = 0;

      protected:
        CEventManager *myEventManager;
    };

    virtual void Exit (std::string &arg) = 0;
    virtual void Help (std::string &arg) = 0;

    virtual void AddOptions (void) = 0;

    CCommandParser() : myEventManager(CEventManager::Instance()) { };
    virtual ~CCommandParser() {};

  protected:
    CEventManager *myEventManager;
};

#endif
