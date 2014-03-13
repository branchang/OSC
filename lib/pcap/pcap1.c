#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
{
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    printf("Device: %s\n", dev);

    pcap_if_t *alldevsp = NULL;

    int ret = pcap_findalldevs(&alldevsp, errbuf);
    int i = 0;
    if(!ret)
    {
        for(i=0;alldevsp[i].next;i++)
        {
            printf("->%s<-\n", alldevsp[i+1].name);
        }
    }

    return(0);
}
