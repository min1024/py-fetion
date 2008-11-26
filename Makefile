# Makefile for PyFetion
# Heihaier <admin@heihaier.org>
# http://www.heihaier.org

CC=g++
CFLAGS=-c -Iinclude `python-config --cflags`
LDFLAGS=-shared `python-config --libs` `curl-config --libs` -Llib -lfetion_32

all : pyfetion.o
	$(CC) -o pyfetion.so $^ $(LDFLAGS)

pyfetion.o : pyfetion.c pyfetion.h methods_help.h
	$(CC) -o $@ $< $(CFLAGS)

clean :
	rm -f *.o *.so

