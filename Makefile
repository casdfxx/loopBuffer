CC = gcc
target = loopBuffer
CFLAG	= -g -O0
CFILE	= loopBuffer.c test.c

$(target):
	$(CC) $(CFLAG) $(CFILE) -o $@

.PYONE clean:
clean:
	rm -f $(target)
	clear

