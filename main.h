
#ifndef main_main_h
#define main_main_h

#include "EventManager.h"

class A
{
  public:

    class A1
    {
      public:
        A1();
        virtual ~A1() {};
    };

    A();
    virtual ~A() {};

    void fireEvents();

    A1 MyA1;
};

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

    void listenerCCommandParser();
    void AddOptions();

    CCommandParser();
    virtual ~CCommandParser() {};

    COptionOne MyCOptionOne;
    COptionTwo MyCOptionTwo;
};

#endif
