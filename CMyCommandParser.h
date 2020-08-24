
#ifndef CMyCommandParser_h
#define CMyCommandParser_h

#include "CEventManager.h"
#include "CCommandParser.h"


class CMyCommandParser : public CCommandParser
{
  public:

    class COptionOne : public CCommandParser::CGenericOption
    {
      public:
        COptionOne() {};
        virtual ~COptionOne() {};
        void listenerCOptionOne (std::string &arg);
        void Add();

        std::string DataItemFilter = "";
    };


    class COptionTwo : public CCommandParser::CGenericOption
    {
      public:
        COptionTwo() {};
        virtual ~COptionTwo() {};
        void listenerCOptionTwo (std::string &arg);
        void Add();

        bool Verbose = false;
    };

    virtual void Exit (std::string &arg);
    virtual void Help (std::string &arg);

    void List (std::string &arg);
    void DataItems (std::string &arg);
    void Request (std::string &arg);
    void Elements (std::string &arg);

    virtual void AddOptions (void);

    CMyCommandParser();
    virtual ~CMyCommandParser() {};

    COptionOne MyCOptionOne;
    COptionTwo MyCOptionTwo;
};

#endif
