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

      printf("createEvent(testEvent-B1a)\n");
      myEventManager->createEvent("testEvent-B1a");

      printf("createEvent(testEvent-B1b)\n");
      myEventManager->createEvent("testEvent-B1b");
    };
  };

  A() {
    // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
    EventManager *myEventManager = EventManager::Instance();
    printf("createEvent(testEvent-B)\n");
    myEventManager->createEvent("testEvent-B");
  }
  
  void fireEvents() {
    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->execute("testEvent-B");
    myEventManager->execute("testEvent-B1a");
    myEventManager->execute("testEvent-B1b");
  }

  A1 MyA1;
};

class B {
public:

  class CSomeBaseClass
  {
  };
  
  class B1a : CSomeBaseClass
  {
    public:
    void listenerB1a() {
      printf("Listener of B1a called\n");
    };

    void attachToEvent() {
      // When testEvent is called the listener method of this class will get called.
      EventManager *myEventManager = EventManager::Instance();

      printf("subscribe(testEvent-B1a)\n");
      myEventManager->subscribe("testEvent-B1a", this, &B::B1a::listenerB1a);
    }
  };


  class B1b : CSomeBaseClass
  {
    public:
    void listenerB1b() {
      printf("Listener of B1b called\n");
    };

    void attachToEvent() {
      // When testEvent is called the listener method of this class will get called.
      EventManager *myEventManager = EventManager::Instance();

      printf("subscribe(testEvent-B1b)\n");
      myEventManager->subscribe("testEvent-B1b", this, &B::B1b::listenerB1b);
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
    
    MyB1a.attachToEvent();
    MyB1b.attachToEvent();
  }

  B1a MyB1a;
  B1b MyB1b;
};

int main() {
  A *obj0 = new A;
  B *obj1 = new B;
  
  obj1->attachToEvent();
  obj0->fireEvents();
  
  return 0;
}
