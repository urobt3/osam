##
##	Makefile for Raspberry Pi Device Driver Programming
##

CC      := gcc

KDIR    := /usr/src/linux

obj-m   := skeleton.o

APP	:= userapp

#PWD	:= `pwd`
PWD	:= $(shell pwd)

default: $(APP)
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

$(APP): $(APP).c
	$(CC) -o $(APP) $(APP).c 

clean:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf .tmp*
	rm -rf *.o
	rm -rf *.order
	rm -f Module.*
	rm -f modules.*
	rm -rf $(APP)

