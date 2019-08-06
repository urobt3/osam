##
##	Makefile for Raspberry Pi (Kernel 4.9.24-v7+) Kernel Module Programming
##
##	FUNFUN modified 2017.05.24.
##


obj-m	:= hello_mod.o

KDIR    = /usr/src/linux

#PWD	:= `pwd`
PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.ko 
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf .tmp*
	rm -rf *.o
	rm -rf *.order
	rm -f Module.*
	rm -f Modules.*
