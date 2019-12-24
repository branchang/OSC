#ifndef TCP_SERVER
#define TCP_SERVER
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Application.h>

using Poco::Util::ServerApplication;
using Poco::Util::Application;

class TCPServer: public ServerApplication{
    public:
        TCPServer();
        ~TCPServer();
    protected:
        void initialize(Application& self);
        void uninitialize();
        int main(const std::vector<std::string>& args);
};



#endif