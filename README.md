Show serial port (tty) signals. There is a s/w called statserial.

This is old code, circa 1997, still works.

E.g.:

```
$ serstatus  /dev/ttyS0
0x4006: RTS    DTR


$ serstatus  /dev/ttyS3
0x4046: RTS    DTR CAR              CD

```
