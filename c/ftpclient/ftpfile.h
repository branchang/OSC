/*
 * =====================================================================================
 *
 *       Filename:  ftpfile.h
 *
 *    Description:  head file
 *
 *        Version:  1.0
 *        Created:  09/17/2013 02:32:44 PM
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
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ioctl.h>

typedef struct ftpHandle{
    //ftp服务器地址
    char url[128];
    //ftp server ip  user inet_addr("192.168.1.1");
    unsigned long ip_addr;
    //data port
    unsigned short data_port;
    int cmdfd;
    char response[1024];
    int datafd;
    int use;
}Handle;

//Handle *ftp_login(char *ftp_server_url, char *name, char *passwd);

//返回文件大小
size_t ftp_get_file(Handle *handle, char *filename, char *saveurl);

size_t ftp_upload_file(Handle *handle, char *fileurl);

size_t ftp_get_file_size(Handle *handle, char *filename);

void ftp_logout(Handle *handle);
