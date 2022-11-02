## Build pixelate_main
## Date: 11-15-2015
## Author: Brad Bahls chembrad@msn.com

CPP=g++
CPPFLAGS=-Wall -O3
CPP11FLAG=-std=c++0x
INCFLAGS=-I/usr/local/include/ -Iinclude/ -I/usr/include/opencv4/

PROJ_LIBDIRS=-Llib/ -L/usr/local/lib/

CVLIBS=-lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_videoio

PREFIX?=$(HOME)
INSTALL=cp -v

all: pixelate

install: pixelate
	$(INSTALL) $^ $(PREFIX)/bin

cvbb.o: cvbb.cpp
	$(CPP) $(CPP11FLAG) $(CPPFLAGS) -c -o $@ $^ $(INCFLAGS)
	
pixelate: cvbb.o pixelate_main.cpp
	$(CPP) $(CPP11FLAG) $(CPPFLAGS) -o $@ $^ $(INCFLAGS) $(PROJ_LIBDIRS) $(CVLIBS)

clean:
	-$(RM) pixelate
	-$(RM) *.o
