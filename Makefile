all: scan.c
	gcc -g -Wall -Werror -o scan scan.c

clean:
	$(RM) scan

run:
	./scan
