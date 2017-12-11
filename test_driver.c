#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
#define STRING__SIZE 501
int main()
{
        int fd, i, choosed;
        int32_t number;
        char value[STRING__SIZE], choose[2];
        printf("****************************\n");
        
        printf("\nOpening Driver\n");
        fd = open("/dev/test_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
        do {
                printf("1: Read date from device \n");
                printf("2: Write date to device \n");
                printf("3: Quit\n");
                printf("Choose: ");
                scanf("%[^\n]%*c", &choose);
                choosed = atoi(choose);
                switch(choosed) {
                        case 1:
                                printf("Reading Value from Driver\n");
                                ioctl(fd, RD_VALUE, &value);
                                printf("Value is %s\n", value);
                                break;
                        case 2:
                                printf("Enter the Value to send\n");
                                scanf("%[^\n]%*c",&value);
                                printf("Writing Value to Driver\n");
                                ioctl(fd, WR_VALUE, &value); 
                                break;
                        case 3:
                                printf("Exit\n"); 
                                break;
                        default:
                        break;
                }
        }while(choosed != 3);
        
        close(fd);
        printf("Closing Driver\n");
        
}
