
#ifndef main_main_h
#define main_main_h

#include "CEventManager.h"

class A
{
  public:

    class A1
    {
      public:
        A1();
        virtual ~A1() {};

      protected:
        CEventManager *myEventManager;
    };

    A();
    virtual ~A() {};

    void fireEvents();

    A1 MyA1;

  protected:
    CEventManager *myEventManager;
};

#endif
