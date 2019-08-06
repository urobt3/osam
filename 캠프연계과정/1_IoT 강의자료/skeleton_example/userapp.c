/**
 **     SKELETON User Application Example for Raspberry Pi
 **
 **/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

static unsigned short flag;

int main(void)
{
	int fd,i;
	int key;
	char *buffer1 = "EFGH";
	char buffer2[256];

	fd = open("/dev/SKELETON", O_RDWR);

	if (fd < 0)
	{
    		printf("USERAPP: /dev/SKELETON isn't opened! \n");
		//exit(1);
		return 1;
	}
    	else
	    	printf("USERAPP: /dev/SKELETON is opened! \n");

    	while((key = main_menu()) != 0)
	{
		switch(key)
		{
	   		case '1':	
				printf("USERAPP: Keyboard [1] is clicked! \n");
				ioctl(fd, 1, flag);
				break;
           		case '2':
                		printf("USERAPP: Keyboard [2] is clicked! \n");
				ioctl(fd, 2, flag);
                		break;
           		case '3':
                		printf("USERAPP: Keyboard [3] is clicked! \n");
				ioctl(fd, 3, flag);
				break;
           		case '4':
                		printf("USERAPP: Keyboard [4] is clicked! \n");
				ioctl(fd, 4, flag);
                		break;
           		case 'w':
                		printf("USERAPP: write() is called! \n");
				write(fd, buffer1, 5);
                		break;
           		case 'r':
                		printf("USERAPP: read() is called! \n");
				read(fd, buffer2, 5);
				printf("USERAPP: Device read data = %s \n", buffer2);
                		break;
           		case 'q':
                		printf("USERAPP: User Application is closed! \n");
				close(fd);
				//exit(-1);
				return 0;
                		break;
                }
        }

        return 0;
} 


int main_menu(void)
{
        int key;
        char input[2];
        printf("\n\n");
        printf("********** [USERAPP] Menu ***********\n");
        printf("* 1.  USERAPP: Keyboard [1]         *\n");
        printf("* 2.  USERAPP: Keyboard [2]         *\n");
        printf("* 3.  USERAPP: Keyboard [3]         *\n");
        printf("* 4.  USERAPP: Keyboard [4]         *\n");
        printf("* w.  USERAPP: write() execute      *\n");
        printf("* r.  USERAPP: read() execute       *\n");
	printf("*                                   *\n");
        printf("* q.  USERAPP: Quit                 *\n");
        printf("*************************************\n");
        printf("\n\n");

	printf("USERAPP: Select the command number : ");
	key = getchar();
	getchar();
	printf("\n\n");

        return key;
}
