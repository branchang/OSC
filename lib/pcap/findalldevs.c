/*
 * =====================================================================================
 *
 *       Filename:  findalldevs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2012 05:03:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "apue.h"
#include <pcap.h>

int main(int argc, char **argv)
{
    pcap_if_t *alldevsp;
    char errbuf[PCAP_ERRBUF_SIZE] = {0};
    int ret = pcap_findalldevs(&alldevsp, errbuf);
    if(ret)
    {
        do{

        }while(alldevsp->);
    }

}
