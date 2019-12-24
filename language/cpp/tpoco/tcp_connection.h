#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/StreamSocket.h>
#include <string>

using namespace Poco::Net;
using namespace std;

class TCPConnection: public TCPServerConnection
{
    public:
        TCPConnection(const StreamSocket& s,const std::string& arg1, int arg2, double arg3);
        void run();
    private:
        std::string _arg1;
        int _arg2;
        double _args;
};

#endif
