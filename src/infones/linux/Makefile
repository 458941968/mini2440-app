CC = arm-linux-gcc
TARBALL = InfoNES08J

# InfoNES
.CFILES =	./../K6502.cpp \
		./../InfoNES.cpp \
		./../InfoNES_Mapper.cpp \
		./../InfoNES_pAPU.cpp \
		./InfoNES_System_Linux.cpp joypad_input.cpp

.OFILES	=	$(.CFILES:.cpp=.o)

CCFLAGS =  -O2 -fsigned-char 
LDFILGS = -lstdc++	-L/home/hyq/workspace/mini2440/mini2440-rootfs/bin/rootfs/usr/lib	# gcc3.x.x
INCLUDES = -I/usr/share/arm/alsa/include
all: InfoNES

InfoNES: $(.OFILES)
	$(CC) $(INCLUDES) -o $@ $(.OFILES) $(LDFILGS) -lm -lz -lpthread -lasound

.cpp.o:
	$(CC) $(INCLUDES) -c $(CCFLAGS) $*.cpp  -o $@

clean:
	rm -f $(.OFILES) ../*~ ../*/*~ core

cleanall:
	rm -f $(.OFILES) ../*~ ../*/*~ core InfoNES

release: clean all

tar:
	( cd ..; \
	tar cvf $(TARBALL).tar ./*; \
	gzip $(TARBALL).tar \
	)

install:
	install ./InfoNES /usr/local/bin
