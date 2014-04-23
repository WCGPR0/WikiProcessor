PROJECT=vwu4_05_project01.tar.gz
CC=g++
CPPFLAGS=-g -std=c++0x -Wall -I ./
SOURCES=Processor.cpp Driver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PACKAGES=$(SOURCES) makefile README.md
EXECUTABLE=wikiParse

all: $(SOURCES) $(EXECUTABLE) 
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $(OBJECTS)

.cpp.o:
	$(CC) -c $(CPPFLAGS) $<

$(PROJECT).tar.gz \
dist:	$(PACKAGES)
	tar -czvf $(PROJECT).tar $(PACKAGES) ./boost
	gzip $(PROJECT).tar

clean:
	rm -f *.o $(EXECUTABLE) report.txt sorted_words.txt
