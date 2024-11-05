Show serial port (tty) pin states. There is also a newer s/w called statserial.

This is old code, circa 1997, still works.

E.g.:

```
$ serstatus  /dev/ttyS0
0x4006: RTS    DTR


$ serstatus  /dev/ttyS3
0x4046: RTS    DTR CAR              CD

```

Nowdays in linux you could just do:
```
cat /proc/tty/driver/serial
serinfo:1.0 driver revision:
0: uart:16550A port:000003F8 irq:4 tx:0 rx:0
1: uart:16550A port:000002F8 irq:3 tx:0 rx:0
2: uart:16550A port:000003E8 irq:6 tx:0 rx:0
3: uart:16550A port:000002E8 irq:7 tx:48039440 rx:78063642 RTS|DTR|CD
4: uart:unknown port:00000000 irq:0
5: uart:unknown port:00000000 irq:0
```
