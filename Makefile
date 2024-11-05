TARGET  = serstatus
CCOPTS =  -O2 -g -Wall
CC = gcc

$(TARGET): *.c
	$(CC) $(CCOPTS) $(DEFS)   -O3 $^ $(LIBS) -o $@

clean:
	@rm -rf *.o core
