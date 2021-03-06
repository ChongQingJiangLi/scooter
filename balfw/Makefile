
VERSION = 0.3a

ifneq ($(RELEASE),)
LIBATMEL:=libatmel
LIBTLB:=libtlb
else
LIBATMEL:=$(HOME)/libatmel
LIBTLB:=$(HOME)/libtlb
endif

# Select one of these to compile for
#TARG=UNICYCLE2
TARG=SEGWELL2
#TARG=ZOOMBOARD
#TARG=JORDANWAY

ARCH = atmega128
UISP_PART = ATmega128

# Must be right to get uart set up correctly
CLOCK_SPEED = 14745600
BAUD_RATE = 115200

# Bootloader is 2K
USE_BOOTLOADER = yes
LDFLAGS_bootloader = -Ttext 0x1f800

# 2 KB bootloader
FUSE_HIGH = 0x8c
FUSE_LOW = 0x3f
FUSE_EXTENDED = 0xff

# The serial PC's serial to talk to the board. Should be a link to, eg, /dev/cuaa0
BOOTLOADPORT = /dev/bootdownload

INCLUDES = -I$(LIBATMEL)
VPATH = $(LIBATMEL)

include $(LIBATMEL)/makedefs.inc

LDFLAGS	= -lm

CFLAGS += -O2

all :: $(ODIR)/bal.srec $(ODIR)/bal.dis $(ODIR)/bootloader.srec

.PRECIOUS: $(ODIR)/bal.srec $(ODIR)/bal.elf

dump-balconf:
	@gcc $(CFLAGS) -E balconf.h

install: all bal.install

bal.objs = $(ODIR)/scooter.o $(ODIR)/adc.o $(ODIR)/uart.o

$(ODIR)/bal.elf: $(bal.objs)

include $(LIBATMEL)/makerules.inc

balfw-$(VERSION) : force
	rm -rf $@
	-mkdir $@
	-mkdir $@/libatmel
	cp LICENSE README $@
	for x in hwdefs.h scooter.c adc.c adc.h balconf.h Makefile; do \
	    add_copyright.py COPYRIGHT $$x $@/`basename $$x`; \
	done
	(echo RELEASE=$(VERSION); cat Makefile) > $@/Makefile
	for x in $(LIBATMEL)/uart.c $(LIBATMEL)/uart.h $(LIBATMEL)/iobits.h $(LIBATMEL)/crc32.c \
	         $(LIBATMEL)/makerules.inc $(LIBATMEL)/makedefs.inc \
	         $(LIBATMEL)/bootloader.c \
	         $(LIBATMEL)/bootdownload.py; do \
	    add_copyright.py COPYRIGHT $$x $@/`basename $$x`; \
	done
	cd $@ && gmake && gmake clean

balfw-$(VERSION).tgz: balfw-$(VERSION)
	tar czf $@ $+

dist: balfw-$(VERSION).tgz
	cp $+ ~/website/tlb
