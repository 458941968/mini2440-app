./configure \
CC=arm-linux-gcc \
CROSS_COMPILE=arm-none-linux-gnueabi- \
--build=i386-linux \
--prefix=/home/hyq/workspace/mini2440/mini2440-app/install/pjproject \
--host=arm-none-linux-gnueabi \
--target=arm-none-linux-gnueabi \
--disable-libyuv --disable-libwebrtc --enable-shared --disable-static \
CFLAGS=-I/usr/share/arm/alsa/include/ CPPFLAGS=-I/usr/share/arm/alsa/include/ LDFLAGS=-L/usr/share/arm/alsa/lib
