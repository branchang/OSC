/*
 * =====================================================================================
 *
 *       Filename:  ftpclient.c
 *
 *    Description:  功能接口文件 为提供各种ftp功能提供的接口
 *
 *        Version:  1.0
 *        Created:  09/17/2013 06:56:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <ftpfile.h>

struct timeval timeout_convert(int timeout)
{
    struct timeval time;
    time.tv_sec = timeout/1000;
    time.tv_usec = timeout%1000;
    return time;
}

//同ftp服务器建立链接
int ftp_connect(Handle *hFtp, int timeout)
{
    int ret = -1;
    unsigned long unblock = 1;
    fd_set write_fd;
    hFtp->cmdfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(21);
    addr.sin_addr.s_addr = hFtp->ip_addr;
    printf("%s \n", inet_ntoa(addr.sin_addr));
    ioctl( hFtp->cmdfd, FIONBIO, &unblock );
    ret = connect(hFtp->cmdfd, (struct sockaddr *)&addr, sizeof(addr));
    if(ret != 0)
    {
        printf("connect faile \n");
        perror("@@@@ \n");
    }
    
    FD_ZERO(&write_fd);
    FD_SET(hFtp->cmdfd, &write_fd);
    struct timeval time;
    time.tv_sec = timeout/1000;
    time.tv_usec = timeout%1000;
    ret = select(hFtp->cmdfd+1, NULL, &write_fd, NULL, &time);
    if(ret <= 0)
    {
        printf("select faile\n");
        goto ERROR_EXIT;
    }

    return 0;

ERROR_EXIT:
    close(hFtp->cmdfd);
    return -1;
}

//建立发送ftp命令数据,返回服务器应答码
char *ftp_send_command(Handle *hFtp, char *type, char *command, int timeout)
{
    int ret = -1;
    char cmdbuf[128];
    char recvbuf[128];
    fd_set read_fd;
    fd_set write_fd;
    
    FD_ZERO(&write_fd);
    FD_ZERO(&read_fd);
    FD_SET(hFtp->cmdfd, &write_fd);
    FD_SET(hFtp->cmdfd, &read_fd);
    memset(cmdbuf, 0, sizeof(cmdbuf));
    memset(recvbuf, 0, sizeof(recvbuf));

    if(type)
    {
        if(command)
        {
            sprintf(cmdbuf, "%s %s \r\n", type ,command );
        }else {
            sprintf(cmdbuf, "%s \r\n", type);
        }
    }
    struct timeval time;
    time = timeout_convert(timeout);
    ret = select(hFtp->cmdfd+1, NULL, &write_fd, NULL, &time);
    if(ret > 0)
    {
        if(FD_ISSET(hFtp->cmdfd, &write_fd))
            send(hFtp->cmdfd, cmdbuf, strlen(cmdbuf), 0); 
    }

    while(select(hFtp->cmdfd+1, &read_fd, NULL, NULL, &time) > 0)
    {
            printf("!%d\n", __LINE__);
            if(FD_ISSET(hFtp->cmdfd, &read_fd))
                recv(hFtp->cmdfd, hFtp->response, sizeof(hFtp->response), 0);
        printf("recvbuf %s \n", hFtp->response);
    }
    
    //解析recvbuf
    return hFtp->response;
}

//接受数据
int ftp_recv_data(Handle *hFtp, char *buf, int size, int timeout)
{
    int ret = -1;
    struct timeval time;
    time = timeout_convert(timeout);
    fd_set read_fd;
    FD_ZERO(&read_fd);
    FD_SET(hFtp->datafd, &read_fd);
    ret = select(hFtp->datafd+1, &read_fd, NULL, NULL, &time);
    if(ret > 0)
    {
        if(FD_ISSET(hFtp->datafd, &read_fd))
            ret = recv(hFtp->datafd, buf, size, 0);
    }

    return ret;
}

//发送数据
int ftp_send_data(Handle *hFtp, char *buf, int size, int timeout)
{
    int ret = -1;
    struct timeval time;
    time = timeout_convert(timeout);
    fd_set write_fd;
    FD_ZERO(&write_fd);
    FD_SET(hFtp->datafd, &write_fd);
    ret = select(hFtp->datafd+1, NULL, &write_fd, NULL, &time);
    if(ret > 0)
    {
        if(FD_ISSET(hFtp->datafd, &write_fd))
            ret = recv(hFtp->datafd, buf, size , 0);
    }
    return ret;
}

//ftp登录
int ftp_login(Handle *hFtp, char *user, char *passwd, int timeout)
{
    int ret = -1;
    char *response;
    //发送登录命令获得返回的类型
    ret = ftp_connect(hFtp, timeout);
    response = ftp_send_command(hFtp, "USER", user, timeout);
    //解析收到的信息
    printf("[%s] \n", response);
    if(atoi(response) == 331 || atoi(response) == 220)
    {
        response = ftp_send_command(hFtp, "PASS", passwd, timeout);
    }

    if(atoi(response) == 230)
    {
        char *ptr = NULL;
        response = ftp_send_command(hFtp, "PASV", NULL, timeout);
        if(ptr = strrchr(response, ','))
        {
            *ptr = '\0';
            hFtp->data_port = atoi(ptr+1); 
            if(ptr = strrchr(response, ','))
            {
                *ptr = '\0';
                hFtp->data_port += atoi(ptr+1)*256;
            }
        }

        //登录成功后建立数据链接
        hFtp->datafd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(hFtp->data_port);
        addr.sin_addr.s_addr = hFtp->ip_addr;
        ret = connect(hFtp->datafd, (struct sockaddr *)&addr, sizeof(addr));
        //select 等待成功链接
    }

    return ret;
}

//ftp推出断开链接
int ftp_disconnect()
{
    return 0;
}


void main(int argc, char** argv)
{
    Handle ftp;
    
    strcpy(ftp.url, "ftp://file.rd.sys.sunniwell.net");
    struct hostent *host_name = NULL;
    host_name = gethostbyname("file.rd.sys.sunniwell.net");
    if(host_name)
    {
        printf("%s\n", host_name->h_addr_list[0]);
        printf("!%d\n", __LINE__);
    }
    //ftp.ip_addr = inet_addr("10.27.40.186");
    ftp.ip_addr = inet_addr("183.81.183.6");
   // ftp.ip_addr = inet_addr(host_name->h_addr_list[0]);

    ftp_login(&ftp, "huawei", "hw515", 1000);
    char *response = NULL;
    //response = ftp_send_command(&ftp, "HELP", NULL, 2000);
    char buf[1024];
    response = ftp_send_command(&ftp, "LIST", NULL, 2000);
    //response = ftp_send_command(&ftp, "PROT", NULL, 2000);
    //response = ftp_send_command(&ftp, "SYST", NULL, 2000);
    int size = -1;
    while((size = ftp_recv_data(&ftp, buf, sizeof(buf), 2000))>0)
    {
        printf("::%s ", buf);
    }
    return ;
}

