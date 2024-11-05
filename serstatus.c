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
    if (r == -1) {
        perror("ioctl");
        exit(1);
    }

    printf("0x%X: ",c);

    if (c&TIOCM_RTS) printf("RTS ") ; else printf("    ");
    if (c&TIOCM_LE)  printf("LE  ") ; else printf("    ");
    if (c&TIOCM_DTR) printf("DTR ") ; else printf("    ");
    if (c&TIOCM_CAR) printf("CAR ") ; else printf("    ");
    if (c&TIOCM_DSR) printf("DSR ") ; else printf("    ");
    if (c&TIOCM_CTS) printf("CTS ") ; else printf("    ");
    if (c&TIOCM_RNG) printf("RING "); else printf("     ");
    if (c&TIOCM_CD)  printf("CD  ") ; else printf("    ");
    printf("\n");

    close(fd);
}
