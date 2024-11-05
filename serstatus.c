/*Spiros Ioannou (sivann at theseas.ntua.gr) 1997
 * Check the modem status*/

#include <fcntl.h>
//#include <termios.h>
//#include <asm/termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
    int     fd;
    int     c=-1;
    int     r;

    if (argc != 2 ) {
        printf("\nUsage: %s tty\n\n",argv[0]);
        exit(1);
    }

    if((fd = open(argv[1], 0)) == -1) {
        fprintf(stderr, "Can't open device: ");
        perror(argv[1]);
        exit(1);
    }
    r = ioctl(fd, TIOCMGET, &c);
    if (!r) {
        perror("ioctl");
        exit(1);
    }

    printf("Current state:%d\n",c);

    if (c&TIOCM_RTS) printf("RTS\n");
    if (c&TIOCM_LE) printf("Line Enable\n");
    if (c&TIOCM_DTR) printf("DTR\n");
    if (c&TIOCM_CAR) printf("CARRIER DETECT\n");
    if (c&TIOCM_DSR) printf("DSR\n");
    if (c&TIOCM_CTS) printf("CTS\n");
    if (c&TIOCM_RNG) printf("RING!\n");
    if (c&TIOCM_CD) printf("CD\n");

    close(fd);
}
