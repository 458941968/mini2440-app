#!/bin/sh
export CFLAGS="-I/home/hyq/workspace/arm/osip2/include"
export LDFLAGS="-L/home/hyq/workspace/arm/osip2/lib -L/home/hyq/workspace/mini2440/mini2440-rootfs/bin/rootfs/usr/lib -lssl -lcrypto"
./configure --target=arm-none-linux-gnueabi --host=arm-none-linux-gnueabi --enable-openssl=yes OSIP_LIBS="-losipparser2 -losip2 -lpthread" -prefix=/home/hyq/workspace/arm/exosip2
