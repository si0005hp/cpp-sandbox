gcc_options = -std=c++2a -Wall --pedantic-error
CPP_FILES := main instanceof any pointer smart_pointer exception object
TARGETS := $(CPP_FILES)

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

dist:
	mkdir -p dist

$(CPP_FILES): all.h all.h.gch dist
	g++ $(gcc_options) -include all.h $@.cpp -o dist/$@

clean:
	rm -rf ./dist
	rm -f ./all.h.gch

.PHONY: run clean
