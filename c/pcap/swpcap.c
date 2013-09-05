/*
 * =====================================================================================
 *
 *       Filename:  swpcap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2012 09:35:42 AM
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
#include <pcap.h>
#include <time.h>

#define DUMP_FILE_PATH "/tmp/dump.cap"
static char device_name[64] = {0};
static char ebuf[PCAP_ERRBUF_SIZE]={0};
static pcap_t *handle = 0;
static int key = 1;
static unsigned int dump_time = -1;
static int dump_size = -1;
static pcap_dumper_t *dfp = NULL;
static long current_time = 0;

/*  
static int swpcap_lookupdev()
{
    int ret = 0;

    device_name = pcap_lookupdev(ebuf);
    if(!device_name)
    {
        fprintf(stderr, "[%s] couldn't find dev : %s\n", __func__, ebuf);
        return ret;
    }else{
        ret = 1;
    }

    return  ret;
}

*/

static int swpcap_open_live(char *device, int snaplen, int promisc, int to_ms)
{
    handle = pcap_open_live(device, snaplen, 1, to_ms, ebuf);
    if(!handle)
    {
        fprintf(stderr, "[%s] couldn't open dev %s : %s \n", __func__,device, ebuf);
        return 0;
    }
    strcpy(device_name, device);
    return 1;
}

static struct bpf_program filter;

//设置过滤类型
static int swpcap_compile_filter(pcap_t *pt, char *str, int optimize)
{
    unsigned int  localnet, netmask;

    if(pcap_lookupnet(device_name, &localnet, &netmask, ebuf) < 0)
    {
       fprintf(stderr,"couldn't look net %s:%s\n", device_name , ebuf); 
       goto err_exit;
    }

    if( pcap_compile(pt, &filter, str, optimize, netmask) < 0)
    {
        fprintf(stderr, "couldn't parse filter %s:%s\n", str, pcap_geterr(pt));
        goto err_exit;
    }

    if(pcap_setfilter(pt, &filter) < 0)
    {
        fprintf(stderr, "couldn't install filter %s:%s\n", str, pcap_geterr(pt));
        goto err_exit;
    }

    pcap_freecode(&filter);

    return 1;

err_exit:
    return 0;
}

//static FILE *fp = NULL;
static int fsize = 0;
void monitor_callback(unsigned char *dump_file, const struct pcap_pkthdr *pk, const unsigned char *pkt_data)
{

    
    if(fsize >= dump_size) {
        pcap_breakloop(handle); //文件大小满足,停止抓包
        printf("pcap_breakloop \n");
    }else  if(dump_file)
    {
        fsize += pk->caplen;
        printf("%d,%d\n",fsize,dump_size );
        pcap_dump(dump_file,pk,pkt_data);
    }

    pcap_dump_flush(dfp);

    struct tm *ltime;//保存时间的结构体
    char timestr[35];//太小就无法保存ltime的时间数据了
    time_t local_tv_sec;///*  时间按总值 */

    /*  将时间戳转换成可识别的格式 */
    local_tv_sec = pk->ts.tv_sec;//得到时间值
    ltime=localtime(&local_tv_sec);//时间存储格式转换
    strftime( timestr, sizeof timestr, "%H时%M分%S秒", ltime);//输出时间并调整输出格式

    printf("时间：%s 秒的值：%.6lu 微秒的值：%.6lu   抓包的长度%u\n",
            timestr,pk->ts.tv_sec, pk->ts.tv_usec, pk->len);
}

int swpcap_dispatch(pcap_t *pt)
{
    int ret = 0;

    //fp = fopen(DUMP_FILE_PATH, "w+");
    while(key)
    {
        ret = pcap_dispatch(pt, 1, monitor_callback, (unsigned char *)dfp);
        if(ret == -1)
        {
            printf("dispatch error : %s\n", pcap_geterr(handle));
        }else if(ret == -2){
            printf("pcap_breakloop recv \n");
            key = 0;
            pcap_dump_flush(dfp);
            pcap_dump_close(dfp);
            pcap_close(handle);
        }else
        {
            long now = time(NULL);
            if((now - current_time) >= dump_time)
            {
                printf("time over ......\n");
                pcap_breakloop(handle);
            }
            printf("dispath num : [%d]%d\n", ret,key);
        }
        
    }

    return 0;
}

//device：设备名称
//filter_type:过滤类型
//tms:抓包时间 s单位
//file_size:抓包大小  M 单位

int swpcap_dump(char *device, char *filter_type, int tms, int file_size)
{

    if(!swpcap_open_live(device, 65535, 1, 100))
    {
        return -1;
    }

    if(!swpcap_compile_filter(handle, filter_type, 1))
    {
        return -1;
    }

    dump_time = tms;  //抓包时间
    dump_size = file_size * 1000 * 1000; //抓包大小
    dfp = pcap_dump_open(handle, DUMP_FILE_PATH);
    current_time = time(NULL);

    swpcap_dispatch(handle);

    return 0;
}


int main(int argc, char **argv)
{

    int ret = -1;
//    swpcap_lookupdev();

    ret =  swpcap_dump("eth0", "ip 10.10.8.27 and port 80", -1, 2);
//  ret =swpcap_dump("eth0","tcp", argv[1], argv[2]);
//  ret = swpcap_open_live(device_name, 0, 1000, 1);
    printf("exit\n");
    return 0;
}
