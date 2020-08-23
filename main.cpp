#include "EventManager.h"
using namespace Mage;

class A {
public:

  class A1
  {
    public:
    A1() {
      // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
      EventManager *myEventManager = EventManager::Instance();

      printf("createEvent(testEvent-COptionOne)\n");
      myEventManager->createEvent("testEvent-COptionOne");

      printf("createEvent(testEvent-COptionTwo)\n");
      myEventManager->createEvent("testEvent-COptionTwo");
    };
  };

  A() {
    // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
    EventManager *myEventManager = EventManager::Instance();
    printf("createEvent(testEvent-CCommandParser)\n");
    myEventManager->createEvent("testEvent-CCommandParser");
  }
  
  void fireEvents() {
    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->execute("testEvent-CCommandParser");
    myEventManager->execute("testEvent-COptionOne");
    myEventManager->execute("testEvent-COptionTwo");
  }

  A1 MyA1;
};

class CCommandParser {
public:

  class CGenericOption
  {
  };
  
  class COptionOne : CGenericOption
  {
    public:
    void listenerCOptionOne() {
      printf("Listener of COptionOne called\n");
    };

    void attachToEvent() {
      // When testEvent is called the listener method of this class will get called.
      EventManager *myEventManager = EventManager::Instance();

      printf("subscribe(testEvent-COptionOne)\n");
      myEventManager->subscribe("testEvent-COptionOne", this, &CCommandParser::COptionOne::listenerCOptionOne);
    }
  };


  class COptionTwo : CGenericOption
  {
    public:
    void listenerCOptionTwo() {
      printf("Listener of COptionTwo called\n");
    };

    void attachToEvent() {
      // When testEvent is called the listener method of this class will get called.
      EventManager *myEventManager = EventManager::Instance();

      printf("subscribe(testEvent-COptionTwo)\n");
      myEventManager->subscribe("testEvent-COptionTwo", this, &CCommandParser::COptionTwo::listenerCOptionTwo);
    }
  };
  
  
  void listenerCCommandParser() {
    printf("Listener of CCommandParser called\n");
  }
  
  void attachToEvent() {
    // When testEvent is called the listener method of this class will get called.
    EventManager *myEventManager = EventManager::Instance();

    printf("subscribe(testEvent-CCommandParser)\n");
    myEventManager->subscribe("testEvent-CCommandParser", this, &CCommandParser::listenerCCommandParser);
    
    MyCOptionOne.attachToEvent();
    MyCOptionTwo.attachToEvent();
  }

  COptionOne MyCOptionOne;
  COptionTwo MyCOptionTwo;
};

int main() {
  A *obj0 = new A;
  CCommandParser *obj1 = new CCommandParser;
  
  obj1->attachToEvent();
  obj0->fireEvents();
  
  return 0;
}
