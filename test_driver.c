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
#define STRING_SIZE 501
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main()
{
        int fd, i, choosed;
        int32_t len;
        char value[STRING_SIZE], choose[2];
        char r_data[STRING_SIZE];
        char command[STRING_SIZE];
        printf("****************************\n");
        
        printf("\nOpening App Test Stack Driver\n");
        fd = open("/dev/etx_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open Stack device file...\n");
                return 0;
        }
        do {
                printf("\n\n1: Read date from Stack device \n");
                printf("2: Write date to Stack device \n");
                printf("3: Quit\n");
                printf("Choose: ");
                scanf("%[^\n]%*c", &choose);
                choosed = atoi(choose);
                switch(choosed) {
                        case 1:
                                printf("Reading Value from Driver\n");
                                len = read(fd,&r_data,sizeof(r_data));
                                if(len > 0) {
                                        printf("%s",r_data);
                                } else {
                                        printf(ANSI_COLOR_RED "Stack is empty" ANSI_COLOR_RESET "\n");
                                }
                                break;
                        case 2:
                                printf("Enter the Value to send\n");
                                scanf("%[^\n]%*c",&value);
                                printf("Writing Value to Driver\n");
                                len = write(fd,&value,sizeof(value));
                                if(len > 0) {
                                        printf(ANSI_COLOR_GREEN "Write to stack success" ANSI_COLOR_RESET "\n");
                                } else {
                                        printf(ANSI_COLOR_RED "Write Error. Stack is full" ANSI_COLOR_RESET "\n");
                                }
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
