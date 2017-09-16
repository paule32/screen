#!/bin/sh
GCC="/usr/local/bin/gcc -Wno-write-strings -O2 -I./"
$GCC -c TObject.cc -o TObject.o
$GCC -c TString.cc -o TString.o
$GCC -c TDesktop.cc -o TDesktop.o
$GCC -c TApplication.cc -o TApplication.o
$GCC -c start.cc -o start.o

/usr/local/bin/gcc -o start TObject.o TString.o TDesktop.o TApplication.o start.o -lstdc++
