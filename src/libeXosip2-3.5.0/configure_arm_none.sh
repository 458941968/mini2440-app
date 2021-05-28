#!/bin/sh
#交叉编译的版本
#prefix根据自己本地路径决定，后面可以由工程相对路径带入，编译时候都自动配置+编译
#

export CC=
export CFLAGS="-DOEMID=${OEMID} -DOEMID_EPIGY=129 -DOEMID_GREENACCESS=130 -I${PJ_INC_DIR} -I${PJ_INC_DIR}/sip -I${PJ_INC_DIR}/sip/cares"
export LIBS=
export CPPFLAGS=
export CXX=
export CXXFLAGS=
export CCC=
export CPP=
export CXXCPP=
export LDFLAGS="-L${PJ_LIB_DIR} -lssl -lcrypto"
./configure --targe=arm-none-linux-gnueabi CC=arm-none-linux-gnueabi-gcc --enable-openssl=yes OSIP_LIBS="-losipparser2 -losip2 -lpthread" -prefix=$PWD/../../objects --exec_prefix=$PWD/../../objects

