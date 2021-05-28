#!/bin/sh
#交叉编译的版本
#prefix根据自己本地路径决定，后面可以由工程相对路径带入，编译时候都自动配置+编译
#
export CC=
export CFLAGS=""
export LIBS=
export CPPFLAGS=
export CXX=
export CXXFLAGS=
export CCC=
export CPP=
export CXXCPP=
export LDFLAGS=

./configure --host=arm-none-linux-gnueabi --prefix=/home/hyq/workspace/arm/osip2
