obj-m += driver.o 
KDIR = /lib/modules/$(shell uname -r)/build
CC=gcc
all:
	make -C $(KDIR)  M=$(shell pwd) modules 
	rm -rf test_driver
	$(CC) -o test_driver test_driver.c -g -w
clean:
	make -C $(KDIR)  M=$(shell pwd) clean