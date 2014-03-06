/*
 * =====================================================================================
 *
 *       Filename:  ping.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/12/2012 09:48:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char** argv)
{
    struct sockaddr_in dest ;
    int socket;

    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(argv[1]);

    socket = socket(AF_INET, DR)



}
