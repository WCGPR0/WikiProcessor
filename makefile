PROJECT=vwu4_05_project01.tar.gz
CC=g++
CPPFLAGS=-g -std=c++11 -Wall
SOURCES=Processor.cpp Driver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PACKAGES=$(SOURCES)
EXECUTABLE=project01

all: $(SOURCES) $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $(OBJECTS)

.cpp.o:
	$(CC) -c $(CPPFLAGS) $<

$(PROJECT).tar.gz \
dist:	$(PACKAGES)
	tar -czvf $(PROJECT).tar $(PACKAGES)
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXECUTABLE)
