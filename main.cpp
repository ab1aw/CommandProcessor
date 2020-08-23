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
      printf("createEvent(testEvent-B1)\n");
      myEventManager->createEvent("testEvent-B1");
    };
  };

  A() {
    // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
    EventManager *myEventManager = EventManager::Instance();
    printf("createEvent(testEvent-B)\n");
    myEventManager->createEvent("testEvent-B");
  }
  
  void fireEvent() {
    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->execute("testEvent-B");
    myEventManager->execute("testEvent-B1");
  }

  A1 MyA1;
};

class B {
public:

  class B1
  {
    public:
    void listenerB1() {
      printf("Listener of B1 called\n");
    };

    void attachToEvent() {
      // When testEvent is called the listener method of this class will get called.
      EventManager *myEventManager = EventManager::Instance();

      printf("subscribe(testEvent-B1)\n");
      myEventManager->subscribe("testEvent-B1", this, &B::B1::listenerB1);
    }
  };
  
  
  void listenerB() {
    printf("Listener of B called\n");
  }
  
  void attachToEvent() {
    // When testEvent is called the listener method of this class will get called.
    EventManager *myEventManager = EventManager::Instance();

    printf("subscribe(testEvent-B)\n");
    myEventManager->subscribe("testEvent-B", this, &B::listenerB);
    
    MyB1.attachToEvent();
  }

  B1 MyB1;
};

int main() {
  A *obj0 = new A;
  B *obj1 = new B;
  
  obj1->attachToEvent();
  obj0->fireEvent();
  
  return 0;
}
