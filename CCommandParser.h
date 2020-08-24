
#ifndef CCommandParser_h
#define CCommandParser_h

#include "EventManager.h"


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

    class COptionOne : public CGenericOption
    {
      public:
        COptionOne() {};
        virtual ~COptionOne() {};
        void listenerCOptionOne (std::string &arg);
        void Add();
    };


    class COptionTwo : CGenericOption
    {
      public:
        COptionTwo() {};
        virtual ~COptionTwo() {};
        void listenerCOptionTwo (std::string &arg);
        void Add();
    };

    virtual void Exit (std::string &arg) = 0;
    virtual void Help (std::string &arg) = 0;

    virtual void AddOptions (void) = 0;

    CCommandParser() {};
    virtual ~CCommandParser() {};
};

#endif
