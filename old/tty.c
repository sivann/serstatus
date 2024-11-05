/*Spiros Ioannou (sivann at theseas.ntua.gr)  1997
 * Check the modem status*/

#include <fcntl.h>
#include <sys/termios.h>
#include <stdio.h>
#include <sys/types.h>

main(int argc,char *argv[])
{
      int     fd;
      int     i=1;
      int     c=-1;
if (argc != 2 ) {printf("\nUsage: %s tty\n\n",argv[0]);exit(1);}

        if((fd = open(argv[1], 0)) == -1) {
                fprintf(stderr, "Cant open device\n");
                exit(1);
        }
ioctl(fd, TIOCMGET, &c);
printf("Current state:%d\n",c);

if (c&TIOCM_RTS) printf("RTS\n");
if (c&TIOCM_LE) printf("Line Enable\n");
if (c&TIOCM_DTR) printf("DTR\n");
if (c&TIOCM_CAR) printf("CARRIER DETECT\n");
if (c&TIOCM_DSR) printf("DSR\n");
if (c&TIOCM_CTS) printf("CTS\n");
if (c&TIOCM_DSR) printf("DSR\n");
if (c&TIOCM_RNG) printf("RING!\n");

close(fd);
}
