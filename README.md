EventManager-Cpp
================

Description
===========
A C++ based Event Manager


Sample Usage
============
<pre><code>
#include "EventManager.h"
using namespace Mage;

class A {
public:
  A() {
  
    // Create a event that will be performed.. doesn't need to be in this class can be defined anywhere.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->createEvent("testEvent");
  }
  
  void fireEvent() {
    // Fire the event and all the subscribed class methods will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->execute("testEvent");
  }
};

class B {
public:
  void listener() {
    printf("Listener of B called");
  }
  
  void attachToEvent() {
    // When testEvent is called the listener method of this class will get called.
    EventManager *myEventManager = EventManager::Instance();
    myEventManager->subscribe("testEvent", this, &B::listener);
  }
};

int main() {
  A *obj0 = new A;
  B *obj1 = new B;
  
  obj1->attachToEvent();
  obj0->fireEvent();
  
  return 0;
}
</code></pre>

Output
======
<em>Listener of B called</em>

License
=======
This code is licensed under <br />
MIT License.
