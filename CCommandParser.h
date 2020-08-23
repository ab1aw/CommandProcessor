
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
        void listenerCOptionOne();
        void Add();
    };


    class COptionTwo : CGenericOption
    {
      public:
        COptionTwo() {};
        virtual ~COptionTwo() {};
        void listenerCOptionTwo();
        void Add();
    };

    void Exit();
    void Help();
    void List();
    void DataItems();
    void Request();
    void Elements();

    void AddOptions();

    CCommandParser();
    virtual ~CCommandParser() {};

    COptionOne MyCOptionOne;
    COptionTwo MyCOptionTwo;
};

#endif
