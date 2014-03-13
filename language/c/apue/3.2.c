/*
 * =====================================================================================
 *
 *       Filename:  3.2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/31/2014 05:54:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int dup2copy(int oldfd, int newfd)
{
    int copyfd = newfd;
    int tmpfd = -1;
    int *filedsarr = malloc(sizeof(int)*newfd); 

    //判断newfd是否打开为打开的文件描述符，如果打开直接关闭
    //由于不能调用fcntl直接close
    tmpfd = dup(newfd);
    if(tmpfd != -1)
    {
        close(newfd);
        close(tmpfd);
    }
    tmpfd = dup(oldfd);
    if(tmpfd == -1)
    {
        free(filedsarr);
        return -1;

    }else {
        close(tmpfd);
    }
    //调用dup直到newfd
    if(oldfd == newfd)
    {
        free(filedsarr);
        return oldfd;
    }

    for(tmpfd = 0; tmpfd < copyfd;)
    {
        tmpfd = dup(oldfd);
        if(tmpfd == -1)
        { 
            free(filedsarr);
            return -1;
        }
        if(tmpfd == copyfd)
        {
            break;
        }
        printf("dup %d \n", tmpfd);
        filedsarr[tmpfd] = 1;
    }

    //关闭dup打开无用的描述符

    for(tmpfd=0;tmpfd < copyfd;tmpfd++)
    {
        if(filedsarr[tmpfd] == 1)
        {
            printf("close fd : %d \n", tmpfd);
            close(tmpfd);
        }
    }

    free(filedsarr);
    return newfd;
}

int main(void)
{

    int fd;
    fd = open("3.2.back", O_RDWR);
    if(fd < 0)
    {
        exit(-1);
    }
    printf("fd : %d\n", fd);
    int fdback = dup2copy(fd, 64);
    printf("fdback : %d\n", fdback);
    return 0;

}
