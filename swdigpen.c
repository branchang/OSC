/***************************************************************************
 *
 * Module Description: Brutus input device code
 *
 * Revision History:
 *
 * 
 *****************************************************************/
#include "stdafx.h"
#include <assert.h>
#include <stdio.h>
#include <errno.h>

/* #include "bsettop_board.h" */
/* #include "bgio.h" */
#include "swboot.h"
#include "swthrd.h"
#include "swqueue.h"
#include "swmsg.h"
#include "swkey.h"
#include "swir.h"
#include "swlog.h"
#if SUPPORT_RANGER
#include "swbrowser_ranger.h"
#else
#include "swbrowser.h"
#endif
#include "swparameter.h"
#include "swmcu.h"
#include "swled.h"
#include "swsignal.h"
#include "swurl.h"
#include "swhttpclient.h"
#include "swdigpen.h"

static HANDLE m_hThrd = NULL;
static PIrCallback m_pcallback_ir;
static unsigned long m_param_dgp;

#if 0
static char *base64_encode(const char* data, int data_len)  
{  
    static const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";  
    //int data_len = strlen(data);  
    int prepare = 0;  
    int ret_len;  
    int temp = 0;  
    char *ret = NULL;  
    char *f = NULL;  
    int tmp = 0;  
    char changed[4];  
    int i = 0;  
    ret_len = data_len / 3;  
    temp = data_len % 3;  
    if (temp > 0)  
    {  
        ret_len += 1;  
    }  
    ret_len = ret_len*4 + 1;  
    ret = (char *)malloc(ret_len);  
      
    if ( ret == NULL)  
    {  
        printf("No enough memory./n");  
        exit(0);  
    }  
    memset(ret, 0, ret_len);  
    f = ret;  
    while (tmp < data_len)  
    {  
        temp = 0;  
        prepare = 0;  
        memset(changed, '\0', 4);  
        while (temp < 3)  
        {  
            printf("tmp = %d\n", tmp);  
            if (tmp >= data_len)  
            {  
                break;  
            }  
            prepare = ((prepare << 8) | (data[tmp] & 0xFF));  
            tmp++;  
            temp++;  
        }  
        prepare = (prepare<<((3-temp)*8));  
        //printf("before for : temp = %d, prepare = %d\n", temp, prepare);  
        for (i = 0; i < 4 ;i++ )  
        {  
            if (temp < i)  
            {  
                changed[i] = 0x40;  
            }  
            else  
            {  
                changed[i] = (prepare>>((3-i)*6)) & 0x3F;  
            }  
            *f = base[changed[i]];  
            //printf("%.2X", changed[i]);  
            f++;  
        }  
    }  
    *f = '\0';  
      
    return ret;  
      
}  
#endif

static unsigned char to_uchar(char ch)
{
    return ch;
}

#define BASE64_LENGTH(inlen) ((((inlen)+2)/3)*4)
static int base64_encode2(const char *in, size_t inlen, char **code)
{
    size_t outlen = 0; 
    outlen = BASE64_LENGTH(inlen) + 1; 
    if(outlen < inlen)
    {
        *code = NULL;
        return -1;
    }

    *code = malloc(outlen);
    if (!(*code))
        return -2;

    char *out = *code;
    static const char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";  

    while(inlen&&outlen)
    {
        sw_log_debug("hello Bran\n");
        *out++ = base64[(to_uchar(in[0]) >> 2) & 0x3f]; 
        if(!outlen--)
            break;
        
        *out++ = base64[((to_uchar(in[0]) << 4) + (--inlen?to_uchar(in[1]>>4):0)) & 0x3f];
        if(!outlen--)
            break;

        *out++ = inlen?base64[((to_uchar(in[1]) << 2) + (--inlen?(to_uchar(in[2]) >> 6):0)) & 0x3f] : '=';
        if(!outlen--)
            break;

        *out++ = inlen?base64[(to_uchar(in[2]) & 0x3f)] : '=';
        if(!outlen--)
            break;

        if(inlen)
            inlen--;
        if(inlen)
            in += 3;
    }

    if (outlen)
        *out = '\0';
    return 0;
}

static int joint_encode(char *url, char *point_code, int length)
{
    if (url == NULL || point_code == NULL)
        return -1;

    int ret = 0;
    memset(url, '\0', 1024);
    char *encode = NULL;
    ret = base64_encode2(point_code, length, &encode);
    //encode = base64_encode(point_code, 33);
    if(ret < 0 || encode == NULL)
    {
        sw_log_warn("[%s][%d]base64_encode error!");
        return -2;
    }
    sw_log_debug("[%s][%d]length %d ->%s encode to %s \n", __FUNCTION__, __LINE__, strlen(encode), point_code, encode);

    if(strcpy(url, COOLHC_URL))
    {
        strncat(url, encode, strlen(encode));
        sw_log_debug("[%s]generate url -> %s \n", __FUNCTION__, url);
    }

    free(encode);

    strcpy(url, "http://172.16.7.131:8080/success.xml");

    return url[0] != '\0'?0:-3;
}

static int parser_xml(char *xml, char **pAdr)
{
    if(xml == NULL)
    {
        sw_log_warn("xml context is NUll");
        return -1;
    }

    char *p = NULL;
    p = strcasestr(xml, XML_DD_SUCCESS);
    if(!p)
    {
        sw_log_warn("xml file format is wrong!");
        return -1;
    }

    p += strlen(XML_DD_SUCCESS);

    if(!strncasecmp(p, "true", 4)) 
    {
        p = strcasestr(xml, XML_URL);
        p += strlen(XML_URL);
        //char *q = strcasestr(url, "</Url>");
        char *q = strcasestr(p, XML_URL_END);
        q[0] = '\0';
        sw_log_debug("parser xml Success is true! url = [%s]\n", p);
        *pAdr = p;
         
    }else{
        p = strcasestr(xml, XML_MESSAGE);
        p += strlen(XML_MESSAGE);
        char *q = strcasestr(p, XML_MESSAGE_END);
        q[0] = '\0';
        sw_log_debug("parser xml not Success , on %s \n", p);

        return -2;
    }

    return 0;
}

static int sw_digpen_conver_url(char *point_code, int code_length)
{

    SURL surl;
    int size = 0;
    int ret = 0;
    int header_size = 0;
    int retcode = 0;
    int timeout = 2 * 1000;
    char hostname[256];
    char buf[16 * 1024];
    char url[1024];
    char sessionid[128];
    HANDLE digpen_client;

    ret = joint_encode(url, point_code, code_length);
    if(ret != 0)
    {
        sw_log_debug("[%s]joint and encode error on %d \n", __FUNCTION__, ret);
        return ret;
    }

    sw_url_parse(&surl, url);
    if(surl.port == 0)
        surl.port = htons(80);
    if(surl.ip == 0)
    {
        sw_log_debug("[%s] ip is NULL!\n", __FUNCTION__);
        return -1;
    }

    digpen_client = sw_httpclient_connect(surl.ip, surl.port, timeout);
    if (digpen_client == NULL)
    {
        sw_log_debug("[%s], connect httpclient failed!\n", __FUNCTION__);
        return -1;
    }
    sw_log_debug("[%s],connect httpclient = %d\n", __FUNCTION__, digpen_client);

    snprintf(hostname, sizeof(hostname), "%s:%d", surl.hostname, ntohs(surl.port));
    sw_log_debug("%s,%d,hostname : %s\n", __FUNCTION__, __LINE__, hostname);

    memset(sessionid, 0, sizeof(sessionid));
    
    /*
    strcpy(sessionid, "Cookie:JSESSIONID=");
    strncat(sessionid, hw_get_sessionid(), sizeof(sessionid));
    sw_log_debug("[%s]:[%d]session:%s\n", __FUNCTION__, __LINE__, sessionid);
    sw_httpclient_register_cookies(digpen_client, sessionid);
    */

    if(!sw_httpclient_request(digpen_client, "GET", surl.path,hostname, NULL,NULL,NULL, 0, timeout, NULL, NULL))
    {
        sw_log_debug("sw_httpclient_request failed!\n");
        sw_httpclient_disconnect(digpen_client);
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    size = sw_httpclient_recv_data(digpen_client, (char *)buf, sizeof(buf), timeout);
    sw_log_info("[%s][%d]http:%s##[size] = %d\n", __FUNCTION__, __LINE__, buf, size);
    header_size = sw_httpclient_get_header_size(buf, size);  
    size -= header_size;
    retcode = sw_httpclient_get_ret_code(buf, sizeof(buf));
    /* 4XX, client error */
    if(retcode/100 == 4 || size <= 0)
    {
        sw_httpclient_disconnect(digpen_client);
        sw_log_debug("[%s]:[%d]http server return code error,ret = %d,size = %d\n", __FUNCTION__, __LINE__, retcode, size);
        return -1;
    }

    memset(url, 0, sizeof(url));
    strncpy(url, buf+header_size, size);

    sw_httpclient_disconnect(digpen_client);
    sw_log_debug("[%s][%d]url:%s\n", __FUNCTION__, __LINE__, url);

    char *pUrl = NULL;
    if(!parser_xml(url, &pUrl))
    {
        sw_log_debug("[%s]:[%d]open %s", __FUNCTION__, __LINE__, pUrl);
        sw_browser_open_url(pUrl);
    }

    return 0;
}

/* 线程工作函数 */
static bool sw_digpen_proc( unsigned long wParam, unsigned long lParam );
 
/* 初始化，delay表示灵敏度，单位ms */
bool sw_digpen_init()
{
	sw_log_debug("sw_digpen_init start!!\n");
	printf("[%s],[%d],[%s]\n", __FILE__, __LINE__, __FUNCTION__); 
	m_hThrd = sw_thrd_open("thrdDigpenProc", 80, 0, 16384, (PThreadHandler)sw_digpen_proc, 0, 0 );
	if( m_hThrd )
	{
		sw_thrd_resume( m_hThrd );		
		sw_log_debug("Digpen: sw_digpen_init OK !!! \n");
		return 1;		 
	}
	return 0;
}

/* 释放资源 */
void sw_digpen_exit()
{
	if(m_hThrd)
	{
		sw_thrd_close(m_hThrd, 1000);	
		m_hThrd = NULL;
	}
}

/* 设置回调函数 */
void sw_digpen_set_callback( PDigPenCallback pProc, unsigned long lParam )
{
    PDigPenCallback pCallback;
    pCallback = pProc;
    lParam = lParam;
	//m_param = lParam;
	//m_pcallback = pProc;
}

/* 线程工作函数 */
static bool sw_digpen_proc( unsigned long wParam, unsigned long lParam )
{
    wParam = wParam;
    lParam = lParam;

	int status = 0;

    return 1;
}

void sw_digpen_ir_callback(PIrCallback pProc, unsigned long lParam)
{
    assert(NULL != pProc);                      
    m_pcallback_ir = pProc;
    m_param_dgp = lParam;
}

int sw_digpen_conver_test()
{
    unsigned char encode[34] = {4, 64, 18, 2, 130, 219, 42, 179,155, 153, 59, 85, 34, 4, 0, 0, 0, 0, 249, 116, 238, 254, 216, 233,177, 68, 2, 0, 61, 224, 0, 2, 3, 0};
    
    //sw_log_debug("encode lenght encode %d", strlen(encode));
    //char buffer[64];
    //memset(buffer, 0, 64);
    //strncpy(buffer, encode, 33);
    //sw_digpen_conver_url(encode, 33);
    sw_detect_hiddev();

    return 0;
}

static int init_hid(int model);
static int hiddev_isExist(void);

#define POINT_DATA_SIZE 34
int sw_detect_hiddev(void)
{

    int hid_fd = -1;
    int code_num = 0;
    char point_buf[POINT_DATA_SIZE];
    if((hid_fd = hiddev_isExist()) > 0)
    {
        do
        {
            memset(point_buf, 0, POINT_DATA_SIZE);
            code_num = read(hid_fd, point_buf, POINT_DATA_SIZE);
            switch(code_num)
            {
                case 33:
                    sw_digpen_conver_url(point_buf, POINT_DATA_SIZE - 1 );
                    break;
                case 0:
                    sw_log_debug("is 0");
                    break;
                default:
                    sw_log_debug("no");
            }
        }while(code_num >= 0);
        
        close(hid_fd);
    }

    sw_log_debug("hid dev close");

    return 1;
}


#define HID_DEV_PATH "/dev/hidraw2"
#define HID_SYSFS_PATH "/sys/class/usb/hiddev0/dev"
#define HID_WRITE_SIZE 8
static int hiddev_isExist(void)
{
    int hid_fd, fd;
    int major, minor;
    char buf[16];

    /*  in some cases, there are two hid_devices, what's done"*/
    fd = open(HID_SYSFS_PATH, O_RDONLY);
     
    if(fd > 0);
    {
        read(fd, buf, sizeof(buf));
        sscanf(buf, "%d:%d", &major, &minor);
        sw_log_debug("[%s][%d]find hid devices %d:%d \n", __FUNCTION__, __LINE__, major, minor);
        close(fd);
        hid_fd = init_hid(O_RDWR);
        return hid_fd > 0?hid_fd:-1;
    }

    return -1;
}

static int init_hid(int model)
{
    /*will open /dev/hidraw2 in here, but in some case maybe hidraw0 or hidraw1*/
    int hid_fd;
    int write_size = 0;
    char write_buf[HID_WRITE_SIZE] = {
        0x05, 0x03,
        0x01, 0x01,
        0x00, 0x00,
        0x00, 0x00
    };
    hid_fd = open(HID_DEV_PATH, model);
    if(hid_fd)
    {
        write_size = write(hid_fd, write_buf, HID_WRITE_SIZE);
        return write < 0? -1:hid_fd;
    }

    return -1;
}
