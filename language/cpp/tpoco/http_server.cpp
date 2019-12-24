#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Util/ServerApplication.h>

#include <iostream>
#include <unistd.h>

using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Net::SocketAddress;

class RequestHandler:public HTTPRequestHandler{
    public:
        void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response){
            response.setChunkedTransferEncoding(true);
            response.setContentType("text/html");
            float f1 = 1;
            float f2 = 939399293993929;
            float f5 = 100000000;
            float f3 = f2/f1;
            while (f1<f5){
                f1+=1;
            }
            std::ostream& ostr = response.send();
            ostr<<"<h1>zhr</h1>"<<f3;
        }
};

class RequestHandlerFactory:public HTTPRequestHandlerFactory
{
    public:
        HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request){
            return new RequestHandler();
        }
};


class Myapp:public ServerApplication
{
    protected:
        int main(const std::vector<std::string>& args){
            SocketAddress socketAddress(Poco::Net::IPAddress(), 8080);
            ServerSocket _serverSock;
            _serverSock.
            // _serverSock.bind(socketAddress, true);
            // _serverSock.listen();
            bool bisListen = false;
            int iListenNum = 0;
            do
            {
                try
                {
                    iListenNum ++;
                    usleep(1000000);
                    _serverSock.bind(socketAddress, true);
                    _serverSock.listen();
                    bisListen = true;
                }
                catch (Poco::Exception &exc)
                {
                    ;
                }
                catch (...)
                {
                    ;
                }
            } while(bisListen == false && iListenNum <= 120);

            HTTPServer HSer(new RequestHandlerFactory, _serverSock, new HTTPServerParams);
            HSer.start();
            std::cout<<"Start"<<std::endl;
            waitForTerminationRequest();
            std::cout<<"Close"<<std::endl;
            HSer.stop();
            return Application::EXIT_OK;
        }
};

int main(int argc, char** argv){
    Myapp app;
    return app.run(argc, argv);
}
