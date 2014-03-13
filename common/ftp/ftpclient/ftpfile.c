/*
 * =====================================================================================
 *
 *       Filename:  ftpfile.c
 *
 *    Description:  ftp client主要实现的是下载文件上传文件功能 
 *
 *        Version:  1.0
 *        Created:  09/17/2013 02:31:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company: 
 *
 * =====================================================================================
 */

#include "ftpclient.h"
#include "ftpfile.h"

//支持32个并发的ftp链接
Handle ftp_pool[32];
void ftp_init()
{
    memset(ftp_pool, 0, sizeof(Handle) * 32);
    return NULL;
}

Handle *ftp_login(char *ftp_server_url, char *name, char *passwd)
{
    int index = 0;
    Handle* ftp_client = NULL;
    for(index; index < sizeof(ftp_pool)/sizeof(Handle); index++)
    {
        if(!ftp_pool[index].use)
        {
            ftp_client = &ftp_pool[index];
            ftp_client->use = 1;
            break;
        }
    }

    if(!ftp_client)
    {
        //没有存在可用的句柄
        return -1;
    }

    strncpy(ftp_client->url, ftp_server_url, strlen(ftp_server_url));
    struct hostent *host_name = NULL;
    host_name = gethostbyname(ftp_server_url);
    ftp_client->ip_addr = inet_addr(host_name->h_addr_list[0]);
    //数据接受端口
    ftp_client->port = 22;

    //socket
    int con_sock = NULL;
    con_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(!con_sock)
    {
        return ;
    }
    bind();
    connect();
    //发送数据
    send();
    //接受数据
    //判断

}

//返回文件大小
size_t ftp_get_file(Handle *handle, char *filename, char *saveurl);

size_t ftp_upload_file(Handle *handle, char *fileurl);

size_t ftp_get_file_size(Handle *handle, char *filename);

void ftp_logout(Handle *handle);
