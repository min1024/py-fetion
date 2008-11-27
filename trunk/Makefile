# Makefile for PyFetion
# Heihaier <admin@heihaier.org>
# http://www.heihaier.org

CC=g++
CFLAGS=-c -Iinclude `python-config --cflags`
LDFLAGS=-shared `python-config --libs` `curl-config --libs` -Llib
LD32FLAGS=$(LDFLAGS) -lfetion_32
LD64FLAGS=$(LDFLAGS) -lfetion_64

pyfetion32 : pyfetion.o
	$(CC) -o pyfetion.so $^ $(LD32FLAGS)

pyfetion64 : pyfetion.o
	$(CC) -o pyfetion.so $^ $(LD64FLAGS)

pyfetion.o : pyfetion.c pyfetion.h methods_help.h
	$(CC) -o $@ $< $(CFLAGS)

help :
	@echo 'make pyfetion32 | pyfetion64 | clean | help'
	@echo '	pyfetion32 : Build PyFetion for i386 (default)'
	@echo '	pyfetion64 : Build PyFetion for amd64'
	@echo '	clean : Clean *.o *.so'
	@echo '	help : Show help information.'

clean :
	rm -f *.o *.so

