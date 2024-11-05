/*Spiros Ioannou (sivann at theseas.ntua.gr) 1997
 * Check the modem status for HPUX 8*/

#include <fcntl.h>
#include <sys/modem.h>
#include <stdio.h>
#include <sys/types.h>

unsigned long     c=0;
main(argc,argv)
int argc;
char *argv[];
{
      int     fd;
      int     i=1;
      unsigned long a1,a1o;
if (argc != 2 ) {printf("\nUsage: %s tty\n\n",argv[0]);exit(1);}

        if((fd = open(argv[1], 0,O_NONBLOCK)) == -1) {
                fprintf(stderr, "Cant open device\n");
                exit(1);
        }

ioctl(fd, MCGETA, &c);
show();
a1=c;
a1o=c;

	while(1){
if ((ioctl(fd, MCGETA, &c))==-1)
perror("IOCTL");

a1=c;
if (a1o!=a1) {
show();
a1o=a1;
}
}
close(fd);
}

show()
{
if (c&MDCD) printf(" CD");else printf("   ");
if (c&MCTS) printf(" CTS");else printf("    ");
if (c&MDSR) printf(" DSR");else printf("    ");
if (c&MRI) printf(" RING!");else printf("      ");
if (c&MRTS) printf(" RTS");else printf("    ");
if (c&MDTR) printf(" DTR");else printf("    ");
if (c&MDRS) printf(" DRS");else printf("    ");
printf("\n*********************************\n");

printf("\n");

}
