
#ifndef CMyCommandParser_h
#define CMyCommandParser_h

#include "CEventManager.h"
#include "CCommandParser.h"


class CMyCommandParser : public CCommandParser
{
  public:

    CMyCommandParser();
    virtual ~CMyCommandParser() {};

    // Required commands.
    virtual void Exit (std::string &arg);
    virtual void Help (std::string &arg);

    //////////////////////////
    // YOUR STUFF STARTS HERE.
    //////////////////////////

    // One class for each of the options that may be associated
    // to one or more commands or subcommands.

    class COptionOne : public CCommandParser::CGenericOption
    {
      public:
        COptionOne() {};
        virtual ~COptionOne() {};
        void listenerCOptionOne (std::string &arg);
        void Add();

        std::string DataItemFilter = "";  // -F option
    };

    class COptionTwo : public CCommandParser::CGenericOption
    {
      public:
        COptionTwo() {};
        virtual ~COptionTwo() {};
        void listenerCOptionTwo (std::string &arg);
        void Add();

        std::string DataItem = "";  // -D option
    };

    class COptionThree : public CCommandParser::CGenericOption
    {
      public:
        COptionThree() {};
        virtual ~COptionThree() {};
        void listenerCOptionThree (std::string &arg);
        void Add();

        bool Verbose = false;  // -V option
    };

    // Application specific commands and subcommands.
    void List (std::string &arg);
    void DataItems (std::string &arg);
    void Request (std::string &arg);
    void Elements (std::string &arg);

    // all this to add options to the commands and subcommands.
    virtual void AddOptions (void);

    // These are the supported options for all the commands and subcommands.
    COptionOne MyOptionOne;
    COptionTwo MyOptionTwo;
    COptionThree MyOptionThree;
};

#endif
