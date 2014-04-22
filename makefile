PROJECT=vwu4_05_project01.tar.gz
CC=g++
CPPFLAGS=-g -std=c++11 -Wall
SOURCES=Processor.cpp Driver.cpp
EXECUTABLE=project01

all: 
	$(CC) $(CPPFLAGS) -o $@ Driver.o Processor.o 

Driver.o: Driver.cpp
	$(CC) $(CPPFLAGS) -c $<

Processor.o: Processor.cpp
	$(CC) $(CPPFLAGS) -c $<
