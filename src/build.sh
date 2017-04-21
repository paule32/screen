gcc -Wno-write-strings -O2 -c TObject.cc -o TObject.o
gcc -Wno-write-strings -O2 -c TString.cc -o TString.o
gcc -Wno-write-strings -O2 -c TDesktop.cc -o TDesktop.o
gcc -Wno-write-strings -O2 -c TApplication.cc -o TApplication.o
gcc -Wno-write-strings -O2 -c start.cc -o start.o

gcc -o start TObject.o TString.o TDesktop.o TApplication.o start.o -lstdc++
