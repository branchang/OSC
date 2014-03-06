#include <stdio.h>

int cfilereplace(char * filename, char * oldstring, char * newstring) 
{ 
    int len=4096; 
    char buff[5000];//文件缓冲区 
    FILE *fd; 
    int i,j,k,flag=0,over=0; 
    int max,readed; 
    int count=0;//搜寻到的数目 
    int oldlen=strlen(oldstring); 
    int newlen=strlen(newstring); 
    int lenstr=(newlen-oldlen); 

    //buff[0]=0x0; 
    //buff[1]=0x0; 
    //打开文件： 
    if((fd = fopen(&filename[0] , "r"))==NULL) 
    { 
        printf("Error : Can not open file %s\n",&filename[0]); 
        return 0; 
    } 
    //读取文件内容 
    while(over != 1) 
    { 
        readed = fread(&buff[0] , 1 , len , fd); 
        if(readed < len) 
        { 
            over=1; 
            max=readed; 
        } 
        else 
        { 
            max=len; 
        } 

        for(i=0;i<max+(count*lenstr);i++) 
        { 
            for(j=0;j<oldlen;j++) 
            { 
                if(*(oldstring+j) != *(buff+i+j)) 
                { 
                    flag=0; 
                    break; 
                } 
                else 
                { 
                    flag=1; 
                } 
            } 
            if(flag==1) 
            { 
                count++; 

                if(lenstr>0) 
                    for(k=max+(count*lenstr);k>i;k--) 
                        *(buff+k+lenstr)=*(buff+k); 
                else if(lenstr<0) 
                    for(k=i;k<max+(count*lenstr);k++) 
                        *(buff+k+oldlen+lenstr)=*(buff+k+oldlen); 

                //buff[max+(count*lenstr)]='{row.content}'; 

                for(k=0;k<newlen;k++) 
                    *(buff+i+k)=*(newstring+k); 

                i+=(newlen); 
            } 
            else 
            { 
                if(j==0) 
                { 
                    i+=(j); 
                } 
                else 
                { 
                    i+=(j-1); 
                } 
            } 
        } 
        //buff[0]=buff[max]; 
        //buff[1]=buff[max+1]; 
        //buff[max]=EOF; 
    } 
    fclose(fd); 
    fd = fopen(&filename[0] , "w"); 
    fwrite(buff,sizeof(char),max+(count*lenstr),fd); 
    fclose(fd); 
    return 1; 
} 

int main(void)
{
    cfilereplace("/home/orange/passwd_back", "huawei", "orange");
}
