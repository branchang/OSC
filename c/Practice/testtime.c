
#include <time.h>
#include <stdio.h>

int main(void)
{
    char tmpbuf[36] = {0}; 
    time_t t = time(NULL);
    struct tm *ltime = localtime(&t);
    strftime(tmpbuf, sizeof(tmpbuf), "%Y%m%d%H%M%S", ltime);
    //printf("%s\n",tmpbuf);
    struct tm test_tm[16];
    printf("%d %d %d\n", sizeof(test_tm), sizeof(struct tm)*16,sizeof(struct tm));

}
