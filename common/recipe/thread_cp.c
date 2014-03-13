#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h> 
#include <dirent.h>
#include <pwd.h>
#include <fcntl.h>
#include <sys/types.h>

#define SIZE 500

struct copy_info
{
        char srcdir[SIZE];
        char tardir[SIZE];
        char srcname[SIZE];
        char tarname[SIZE];
};

struct task
{
        void (*job)(struct copy_info);
        struct copy_info arg;

        struct task *next;
};

struct thread_pool
{
        pthread_mutex_t m;
        sem_t s;

        struct task *head;

        pthread_t *tids;

        unsigned thread_num;
        unsigned task_num;
};

static struct thread_pool *pool;
char dir[50];

#if 1
void *routine(void *arg)
{
        while(1){
                printf("pthread routine\n");
                // waiting for a task to run
                sem_wait(&pool->s);

                // lock task queue, and consume the task
                pthread_mutex_lock(&pool->m);

                struct task *p = pool->head->next;
                pool->head->next = p->next;

                pthread_mutex_unlock(&pool->m);

                // execute the job
                (p->job)(p->arg);
                pool->task_num--;
                free(p);
                p = NULL;
        }
}
#endif

#if 1
void pool_init(int thread_num)
{
        pool = (struct thread_pool *)malloc(sizeof(struct thread_pool));

        pthread_mutex_init(&pool->m, NULL);
        sem_init(&pool->s, 0, 0);

        struct task *p = (struct task *)malloc(sizeof(struct task));
        p->next = NULL;
        pool->head = p;

        pool->tids = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);

        pool->thread_num = thread_num;
        pool->task_num = 0;

        int i;
        for(i=0; i<thread_num; i++)
                pthread_create(pool->tids+i, NULL, routine, NULL);
}
#endif

void add_task(void (*job)(struct copy_info), struct copy_info arg)
{
        while(pool->task_num >= 10);

        struct task *newtask = (struct task *)malloc(sizeof(struct task));
        newtask->job = job;
        newtask->arg = arg;
        newtask->next = NULL;

        pthread_mutex_lock(&pool->m);

        struct task *p = pool->head;
        while(p->next != NULL)
                p = p->next;

        p->next = newtask;

        pool->task_num++;

        pthread_mutex_unlock(&pool->m);

        sem_post(&pool->s);
}

void copy_file(struct copy_info info)
{
        int fd1, fd2;
        ssize_t m, n;
        char buf[1000];
        char *p;

#ifdef DEBUG
                printf("tid = %u\n", (unsigned)pthread_self());
                printf("srcdir = %s, srcfile = %s\n", info.srcdir, info.srcname);
                printf("tardir = %s, tarfile = %s\n", info.tardir, info.tarname);
#endif

        
        
        chdir(info.srcdir);
        fd1 = open(info.srcname, O_RDONLY);
        if(fd1 == -1)
        {
                perror("open file");
                exit(1);
        }
        chdir(info.tardir);
        fd2 = open(info.tarname, O_RDWR | O_CREAT, 0777);
        if(fd2 == -1)
        {
                perror("open file");
                exit(1);
        }

        while(1)
        {
//                chdir(info.srcdir);

                n = read(fd1, buf, 1000);
                if(n == -1)
                {
                        perror("read file");
                        exit(1);
                }
                else if(!n)
                        break;

                m = 0;
                p = buf;
//                chdir(info.tardir);
                while(n)
                {
                        n = n - m;
                        p = p + m;
                        m = write(fd2, p, n);
                        if(m == -1)
                        {
                                perror("write file");
                                exit(1);
                        }
                }
        }
        close(fd1);
        close(fd2);
}

void copy_dir(char *src, char *tar)
{
        int i;

        char newsrc[SIZE];
        char newtar[SIZE];
        char newname[SIZE];
        char sysstr[SIZE];

        memset(newsrc, 0, SIZE);
        memset(newtar, 0, SIZE);
        memset(sysstr, 0, SIZE);
        memset(newname, 0, SIZE);

        strcpy(newsrc, src);
        strcpy(newtar, tar);

//        sprintf(sysstr, "mkdir %s\n", newtar);
//        system(sysstr);
        mkdir(newtar, 0777);

        DIR *dp;
//        chdir(newsrc);
//        chdir("..");
        dp = opendir(newsrc);
        chdir(newsrc);
//        get_current_dir_name();

        struct copy_info info;
        memset(info.srcdir, 0, SIZE);
        memset(info.tardir, 0, SIZE);
        memset(info.srcname, 0, SIZE);
        memset(info.tarname, 0, SIZE);
        
        struct dirent *ep;
        while(1)
        {
                strcpy(newsrc, src);
                strcpy(newtar, tar);

                ep = readdir(dp);
                if(ep == NULL)
                        break;
        
                if(ep->d_name[0] == '.')
                        continue;

                struct stat buf;
                strcpy(newname, newsrc);
                for(i=0; newname[i]!='\0'; i++);
                if(newname[i-1] != '/')
                        strcat(newsrc, "/");
                strcat(newname, ep->d_name);
                
                lstat(newname, &buf);
                if(S_ISDIR(buf.st_mode))
                {
                        for(i=0; newsrc[i]!='\0'; i++);
                        if(newsrc[i-1] != '/')
                                strcat(newsrc, "/");
                        strcat(newsrc, ep->d_name);


                        for(i=0; newtar[i]!='\0'; i++);
                        if(newtar[i-1] != '/')
                                strcat(newtar, "/");
                        strcat(newtar, ep->d_name);

                        copy_dir(newsrc, newtar);
                }
                else
                {
                        strcpy(info.srcdir, newsrc);
                        strcpy(info.tardir, newtar);
                        strcpy(info.srcname, ep->d_name);
                        strcpy(info.tarname, ep->d_name);

                        add_task(copy_file, info);
                }
        }
}

void getinfo(struct copy_info *info, char *src, char *tar)
{
        int i, j;
        for(i=0; src[i]!='\0' && src[i]!='/'; i++);
        if(src[i] == '/')
        {
                for(; src[i]!='\0'; i++);
                for(j=i; src[j]!='/'; j--);
                for(i=0; i<j; i++)
                        info->srcdir[i] = src[i];

                for(i=j+1; src[i]!='\0'; i++)
                        info->srcname[i-j-1] = src[i];
        }
        else
        {
                strcpy(info->srcdir, ".");
                strcpy(info->srcname, src);
        }

        for(i=0; tar[i]!='\0' && tar[i]!='/'; i++);
        if(tar[i] == '/')
        {
                for(; tar[i]!='\0'; i++);
                for(j=i; tar[j]!='/'; j--);
                for(i=0; i<j; i++)
                        info->tardir[i] = tar[i];

                for(i=j+1; tar[i]!='\0'; i++)
                        info->tarname[i-j-1] = tar[i];
        }
        else
        {
                strcpy(info->tardir, ".");
                strcpy(info->tarname, tar);
        }
}


int main(int argc, char *argv[])
{
        umask(0);

        char src[SIZE] = "/home/orange/Notebooks/";
        char tar[SIZE] = "/home/orange/Videos/";

#if 0
        strcpy(src, argv[1]);
        strcpy(tar, argv[2]);

        if(argc != 3)
        {
                printf("arguments not match.\n");
                exit(1);
        }
#endif        
        
        
        

        pool_init(3);
        printf("init finished\n");

        int fd = open(src, O_RDONLY);
        if(fd == -1)
        {
                printf("can not find file.\n");
                exit(1);
        }

        struct stat buf;
        if(fstat(fd, &buf) == -1)
        {
                printf("read stat fail.\n");
                exit(1);
        }
        close(fd);

        if(S_ISDIR(buf.st_mode))
                copy_dir(src, tar);
        else
        {
                struct copy_info info;
                memset(info.srcdir, 0, SIZE);
                memset(info.tardir, 0, SIZE);
                memset(info.srcname, 0, SIZE);
                memset(info.tarname, 0, SIZE);
                getinfo(&info, src, tar);
                add_task(copy_file, info);
        }
                
        pause();
        
        return 0;
}
