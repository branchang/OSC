//
// Created by Bran on 9/11/18.
//

#include "TestPoco.h"

TestPoco::TestPoco(){

}
void TestPoco::run() {
    printf("run test poco!\n");
    // t_byte_order();
    t_any();
    // t_json();
    // JsonGet();
    // JsonArray();
    JsonGetArray();
}

int TestPoco::t_byte_order() {
#ifdef POCO_ARCH_LITTLE_ENDIAN
    std::cout<<"little endian"<<std::endl;
#else
    std::cout<<"big endian"<<std::endl;
#endif

    UInt16 port = 80;
    UInt16 newworkPort = ByteOrder::toNetwork(port);
    std::cout<<port<<","<<newworkPort<<std::endl;

    return 0;
}

int TestPoco::t_any() {
    Any any(42);
//    int i = AnyCast<int>(any);
//    int& ri = RefAnyCast<int>(any);

    try{
//        short s = AnyCast<short>(any);
        ;
    }catch (Poco::BadCastException){

    }
    return 0;
}

void TestPoco::t_json(){

    JSON::Object jsnObj;
    JSON::Array jsnArry;
    JSON::Object subObj1;
    JSON::Object subObj2;

    jsnObj.set( "command", "createuser" );

    subObj1.set( "name", "yuhaiyang");
    subObj1.set( "pass", "123" );

    subObj2.set( "name", "cj" );
    subObj2.set( "pass", "456" );

    jsnArry.add( subObj1 );
    jsnArry.add( subObj2 );

    jsnObj.set( "userinfo", jsnArry );

    std::stringstream  jsnOstream;
    jsnObj.stringify( jsnOstream, 3 );

    string jsnStr = jsnOstream.str();

    std::cout << "原数据:\n" << jsnStr << "\n\n\n" << std::endl;


    //--------------------------解析数组-----------------------------
    JSON::Parser parse;
    Dynamic::Var json = parse.parse( jsnStr );
    JSON::Object::Ptr pObj = json.extract<JSON::Object::Ptr>();
    JSON::Array::Ptr pArry = pObj->getArray( "userinfo" );

    JSON::Array::ConstIterator it = pArry->begin();
    //把数组里的所有内容打印出来
    //当然也可以把每个对象拿出来用。
    for ( ; it != pArry->end(); it++ )
    {
        std::cout << it->toString() << std::endl;
    }

}

void TestPoco::JsonGet(){
    string jsonString = "{\"name\":\"yuhaiyang\"}";
    JSON::Parser parser;
    Dynamic::Var result;
    parser.reset();

    result = parser.parse(jsonString);
    JSON::Object::Ptr pObj = result.extract<JSON::Object::Ptr>();

    Dynamic::Var ret = pObj->get("name");
    if (ret.isEmpty()){
        std::cout<<"is null" <<std::endl;
    }else{
        std::cout<<ret.toString()<<std::endl;
    }
}

void TestPoco::JsonArray(void){
    JSON::Object jsnObj;
    JSON::Array jsnArray;
    JSON::Object subObj1;
    JSON::Object subObj2;

    jsnObj.set("command", "createuser");

    subObj1.set("name", "yuhaiyang");
    subObj1.set("pass", "123");

    subObj2.set("name", "cj");
    subObj2.set("pass", "456");

    jsnArray.add(subObj1);
    jsnArray.add(subObj2);

    jsnObj.set("userinfo", jsnArray);

    std::stringstream jsnString;
    jsnObj.stringify(jsnString, 3);
    std::cout<<jsnString.str()<<std::endl;
}

void TestPoco::JsonGetArray(void){
    JSON::Object jsnObj;
    JSON::Array jsnArray;
    JSON::Object subObj1;
    JSON::Object subObj2;
   
    jsnObj.set("command", "createuser");

    subObj1.set("name", "yuhaiyang");
    subObj1.set("pass", "123");

    subObj2.set("name", "cj");
    subObj2.set("pass", "456");

    jsnArray.add(subObj1);
    jsnArray.add(subObj2);

    jsnObj.set("userinfo", jsnArray);

    std::stringstream jsnString;
    jsnObj.stringify(jsnString, 3);
    std::cout<<jsnString.str()<<std::endl;

    std::stringstream jsnOstream;
    jsnObj.stringify(jsnOstream, 3);

    string jsnStr = jsnOstream.str();

    JSON::Parser parse;
    Dynamic::Var json = parse.parse(jsnStr);
    JSON::Object::Ptr pObj = json.extract<JSON::Object::Ptr>();
    JSON::Array::Ptr pArry = pObj->getArray("userinfo");

    JSON::Array::ConstIterator it = pArry->begin();
    for (;it!=pArry->end();it++){
        std::cout << it->toString() <<std::endl;
    }
}

