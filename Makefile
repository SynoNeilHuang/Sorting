CXX=g++

ALLSRC := $(wildcard *.cpp)
SORTSRC := $(filter-out main.cpp, $(wildcard *.cpp))
SORTLIB := $(SORTSRC:%.cpp=%.o)
SORTSHARED := libsort.so

CXXFLAGS := -O3 -std=c++11
INC_PATH := .
LIB_PATH := .

.PHONY: all clean

all: main

deps := $(ALLSRC:%.cpp=.%.o.d)

main: main.cpp $(SORTSHARED)
	$(CXX) $(CXXFLAGS) -o $@ $< -I$(INC_PATH) -L$(LIB_PATH) -lsort -MMD -MF .$@.o.d

$(SORTSHARED): $(SORTLIB)
	$(CXX) -shared -o $(SORTSHARED) $^

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c -MMD -MF .$@.d $< -fPIC -I$(INC_PATH)

clean:
	$(RM) main $(SORTLIB) $(SORTSHARED) $(deps)

-include $(deps)
