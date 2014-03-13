/*
 * =====================================================================================
 *
 *       Filename:  3.6.c
 *
 *    Description:  if a file is opend with append, lseek func is also usefull?
 *
 *        Version:  1.0
 *        Created:  01/31/2014 06:58:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = -1;
    fd = open("3.2.back", O_RDWR|O_APPEND);
    if(fd < 0 )
    {
        printf("open file error \n");
        return -1;
    }

    int seek = lseek(fd, 0, SEEK_SET);
    if(seek == -1)
    {
        return -1;
    }
    printf("file seek to %d \n", seek);
    
    char buf[32] = {0};
//    char buf[32] = "12345667890";
    read(fd, buf, sizeof(buf));
    printf("read %s \n", buf);
    int num = write(fd, buf,strlen(buf));
    printf("write %d %d %s \n", num, strlen(buf), buf);
    perror("111");

    fsync(fd);
    close(fd);
    return -1;
    
}
