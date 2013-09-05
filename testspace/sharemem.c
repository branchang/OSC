/*
 * =====================================================================================
 *
 *       Filename:  sharemem.c
 *
 *    Description:  共享内存 
 *
 *        Version:  1.0
 *        Created:  08/27/2013 10:16:38 PM
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
#include <sys/mman.h>

void* shmem_alloc(size_t size)
{
    g_shmem_fd = open("/dev/shm/demo", O_RDWR);
    if(g_shmem_fd < 0)
    {
        void *buf = NULL;
        buf = calloc(size, 1);
        g_shmem_fd = open("/dev/shm/demo", O_RDWR|O_CREAT,0640);
        write(g_shmem_fd, buf, size);
        free(buf);
    }
    void *addr = mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, g_shmem_fd, size, 0);

    return addr;
}

void shmem_free(void *addr, size_t size)
{
    munmap(addr, size);
    close(g_shmem_fd);

    return;
}

