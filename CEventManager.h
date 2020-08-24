
#ifndef CEventManager_CEventManager_h
#define CEventManager_CEventManager_h

#include <vector>
#include <map>
#include <string>

using namespace std;

#define TEMPLATE template <typename Class>

// Abstract Class for CEventHandler to notify of a change
class CEventHandlerBase
{
  public:
    virtual void execute (std::string &arg) = 0;
};

// CEvent Handler Class : Handles Callback
template <typename Class>
class CEventHandler : public CEventHandlerBase
{
    // Defining type for function pointer
    typedef void (Class::*_fptr) ( std::string &arg);

  public:
    // Object of the Listener
    Class *object;
    // Function for callback
    _fptr function;
    // Optional argument for the function.
    std::string argument;

    CEventHandler (Class *obj, _fptr func)
    {
      object = obj;
      function = func;
      argument = "";
    }

    CEventHandler (Class *obj, _fptr func,  std::string &arg)
    {
      object = obj;
      function = func;
      argument = arg;
    }

    void execute ( std::string &arg)
    {
      (object->*function) (arg);
    }
};

// Class to create a event
class CEvent
{
    // To store all listeners of the event
    typedef std::map<int, CEventHandlerBase*> CEventHandlerMap;
    CEventHandlerMap handlers;
    int count;
  public:

    template <typename Class>
    void addListener (Class *obj, void (Class::*func) ( std::string &arg) )
    {
      handlers[count] = new CEventHandler<Class> (obj, func);
      count++;
    }

    template <typename Class>
    void addListener (Class *obj, void (Class::*func) ( std::string &arg),  std::string &arg)
    {
      handlers[count] = new CEventHandler<Class> (obj, func, arg);
      count++;
    }

    void execute ( std::string &arg)
    {
      for (CEventHandlerMap::iterator it = handlers.begin(); it != handlers.end(); ++it)
      {
        it->second->execute (arg);
      }
    }

};

class CEventManager
{
    struct CEventType
    {
      CEvent *event;
      string name;
    };

    std::vector<CEventType> _events;

    static CEventManager *_Instance;

    CEventManager() {};

  public:
    static CEventManager* Instance()
    {
      if (!_Instance)
      {
        _Instance = new CEventManager();
      }

      return _Instance;
    }

    void createEvent (string name)
    {
      for (vector<CEventType>::iterator it = _events.begin(); it != _events.end(); ++it)
      {
        CEventType e = *it;

        if (e.name.compare (name) == 0)
        {
          return;
        }
      }

      CEventType e;
      e.event = new CEvent();
      e.name = name;
      _events.push_back (e);
    }

    template <typename Class>
    bool subscribe (string name, Class *obj, void (Class::*func) (std::string &arg) )
    {
      for (vector<CEventType>::iterator it = _events.begin(); it != _events.end(); ++it)
      {
        CEventType e = *it;

        if (e.name.compare (name) == 0)
        {
          e.event->addListener (obj, func);
          return true;
        }
      }

      return false;
    }

    template <typename Class>
    bool subscribe (string name, Class *obj, void (Class::*func) (void), std::string &arg)
    {
      for (vector<CEventType>::iterator it = _events.begin(); it != _events.end(); ++it)
      {
        CEventType e = *it;

        if (e.name.compare (name) == 0)
        {
          e.event->addListener (obj, func, arg);
          return true;
        }
      }

      return false;
    }

    void execute ( string name)
    {
      for (vector<CEventType>::iterator it = _events.begin(); it != _events.end(); ++it)
      {
        CEventType e = *it;

        if (e.name.compare (name) == 0)
        {
          static std::string dummy ("");
          e.event->execute (dummy);
        }
      }
    }

    void execute ( string name, std::string &arg)
    {
      for (vector<CEventType>::iterator it = _events.begin(); it != _events.end(); ++it)
      {
        CEventType e = *it;

        if (e.name.compare (name) == 0)
        {
          e.event->execute (arg);
        }
      }
    }
};

#endif
