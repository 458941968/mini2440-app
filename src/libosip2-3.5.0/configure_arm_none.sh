#!/bin/sh
#�������İ汾
#prefix�����Լ�����·����������������ɹ������·�����룬����ʱ���Զ�����+����
#
export CC=
export CFLAGS="-DOEMID=${OEMID} -DOEMID_EPIGY=129 -DOEMID_GREENACCESS=130 -I${PJ_INC_DIR}/sip -I${PJ_INC_DIR}"
export LIBS=
export CPPFLAGS=
export CXX=
export CXXFLAGS=
export CCC=
export CPP=
export CXXCPP=
export LDFLAGS=

./configure --host=arm-none-linux-gnueabi CC=arm-none-linux-gnueabi-gcc --prefix=$PWD/../../objects
