//
// Created by Bran on 9/11/18.
//

#ifndef CPP_TESTPOCO_H
#define CPP_TESTPOCO_H

#include <iostream>
#include <Poco/Util/Application.h>
#include <Poco/Foundation.h>
#include <Poco/ByteOrder.h>
#include <Poco/Any.h>
#include <Poco/Exception.h>
#include <Poco/Dynamic/Struct.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/ParseHandler.h>
#include <Poco/JSON/JSONException.h>
#include <Poco/StreamCopier.h>

using Poco::ByteOrder;
using Poco::UInt16;

using Poco::Any;
using Poco::AnyCast;
using Poco::RefAnyCast;
using Poco::DynamicStruct;
using namespace Poco::Dynamic;
using namespace Poco;
using namespace std;

class TestPoco {
public:
    TestPoco();
    void JsonArray(void);
    void JsonGet();
    void JsonGetArray(void);
    void run();

protected:
    int t_byte_order();
    int t_any();
    void t_json();
};


#endif //CPP_TESTPOCO_H
