#ifndef TCP_CONNECT_FACTORY_H
#define TCP_CONNECT_FACTROY_H
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/StreamSocket.h>
#include <string>

class TTCPConnectionFactory:public TCPServerConnectionFactory
{
    public:
         TTCPConnectionFactory(const std::string arg1, int arg2, double arg3)
        : _arg1(arg1), _arg2(arg2), _arg3(arg3)
    {
    }
 
    TCPServerConnection* createConnection(const StreamSocket& socket)
    {
        return new TCPConnection(socket, arg1, arg2, arg3);
    }

    private:
        std::string arg1;
        int arg2;
        double arg3;
};

#endif 