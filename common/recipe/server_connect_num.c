#include <stdio.h>
int main(int argc, char* argv[])
{
/*        ParseArgs(argc, argv);*/

        char szServerIP[16] = {0};
        short nPort = -1;
        int nConnNumber = -1;
        int nTestType = -1;
        int ch;
        while((ch = getopt(argc, argv, "s:p:m:t:")) != -1)
        {
                switch(ch)
                {
                case 's':
                        {
                                strcpy(szServerIP, optarg);
                                break;
                        }
                case 'p':
                        {
                                nPort = atoi(optarg);
                                if(nPort < 1024)
                                {
                                        LOG_1("invalid port, port=%d", nPort);
                                }
                                break;
                        }
                case 'm'://这里指定最大连接数，我启动时给的值是100
                        {
                                nConnNumber = atoi(optarg);
                                if (nConnNumber < 0)
                                {
                                        LOG_1("invalid connect number, m=%d", nConnNumber);
                                }
                                break;
                        }
                case 't':
                        {
                                nTestType = atoi(optarg);
                                if (nTestType < 0)
                                {
                                        nTestType = -1;
                                        LOG_1("invalid test type , nTestType=%d", nTestType);
                                }
                                break;
                        }
                default:
                        {
                                Usage();
                                return 0;
                        }
                }
        }
        
        if(strlen(szServerIP) == 0)
                strcpy(szServerIP, "127.0.0.1");
        if (nPort <= 0)
                nPort = 9528;
        if(nConnNumber <= 0)
                nConnNumber = 1;
        
        g_nMaxConnCount = nConnNumber;
        for (int i = 0; i < nConnNumber; i++)
        {
                CConnectInstance* pConnInstance = new CConnectInstance(i + 1, nTestType);
                pConnInstance->SetServerAddr(szServerIP, nPort);
                pConnInstance->ConnectToServer();
        }

        while(1);

        return 0;
}
