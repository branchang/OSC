#include <Poco/Net/DNS.h>
#include <iostream>

using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;


int main(int argc, char** argv){
    const HostEntry& entry = DNS::hostByName("www.taobao.cn");
    std::cout<<"Canonical Name: "<<entry.name()<<std::endl;

    const HostEntry::AliasList& aliases = entry.aliases();
    HostEntry::AliasList::const_iterator it = aliases.begin();
    for(;it!=aliases.end();++it){
        std::cout<<"Alias: "<<*it<<std::endl;
    }

    const HostEntry::AddressList& addrs = entry.addresses();
    HostEntry::AddressList::const_iterator it2 = addrs.begin();
    for (;it2!=addrs.end(); ++it2)
        std::cout << "Address: " << it2->toString() << std::endl;
    return 0;
}