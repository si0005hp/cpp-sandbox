gcc_options = -std=c++2a -Wall --pedantic-error
CPP_FILES := main instanceof any pointer smart_pointer exception object optional friend virtual string \
							operator_overload template map ostream struct constructor reference fs container free lambda \
							const move unique_ptr inheritance memory array

EFFECTIVE_CPP_FILES := introduction 3 7

TARGETS := $(CPP_FILES)

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

dist:
	mkdir -p dist

$(CPP_FILES): all.h all.h.gch dist
	g++ $(gcc_options) -include all.h $@.cpp -o dist/$@

$(EFFECTIVE_CPP_FILES): all.h all.h.gch dist
	g++ $(gcc_options) -include all.h effective_cpp/$@.cpp -o dist/$@

clean:
	rm -rf ./dist
	rm -f ./all.h.gch

.PHONY: run clean
