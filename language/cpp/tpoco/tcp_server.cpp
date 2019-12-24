#include "tcp_server.h"

void TCPServer::initialize(Application& self){
    ServerApplication::loadConfiguration();
    ServerApplication::initialize(self);
}

void TCPServer::uninitialize(){
    ServerApplication::uninitialize();
}

int TCPServer::main(const std::vector<std::string>& args){
    

    return Application::EXIT_OK;
}