
#include "tcp_connection.h"
#include <Poco/Util/Application.h>
#include <Poco/Timestamp.h>
#include <Poco/Exception.h>
#include <Poco/DateTimeFormatter.h>

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
TCPConnection::TCPConnection(const StreamSocket& s, const std::string& arg1, int arg2, double arg3):
    TCPServerConnection(s), _arg1(arg1), _arg2(arg2), _arg3(arg3)
    {

    }

void TCPConnection::run()
{
    Application& app = Application::instance();

    app.logger().information("Request from " + this->socket().peerAddress().toString());
    try{
        Timestamp now;
        std::string dt(DateTimeFormatter::format(now, _format));
        dt.append("\r\n");
        socket().sendBytes(dt.data(), (int)dt.length());

    }catch (Poco::Exception& e){
        app.logger().log(e);
    }
}
