
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
        void listenerCOptionOne(std::string &arg);
        void Add();
    };


    class COptionTwo : CGenericOption
    {
      public:
        COptionTwo() {};
        virtual ~COptionTwo() {};
        void listenerCOptionTwo(std::string &arg);
        void Add();
    };

    void Exit(std::string &arg);
    void Help(std::string &arg);
    void List(std::string &arg);
    void DataItems(std::string &arg);
    void Request(std::string &arg);
    void Elements(std::string &arg);

    void AddOptions(void);

    CCommandParser();
    virtual ~CCommandParser() {};

    COptionOne MyCOptionOne;
    COptionTwo MyCOptionTwo;
};

#endif
