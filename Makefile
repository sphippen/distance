CXX = g++
CC = gcc
CPPFLAGS = -Wall -O3 -MMD
CXXFLAGS = -std=c++11
BIN = distance
CPPSRCS = $(wildcard *.cpp)
DEPENDS = $(CPPSRCS:.cpp=.d)
OBJS = $(CPPSRCS:.cpp=.o)
LIBS = -lpng

$(BIN) : $(OBJS)
	$(CXX) -o $(BIN) $(LIBS) $(OBJS)

.PHONY: clean
clean:
	rm -rf $(DEPENDS) $(OBJS) $(BIN) out*

-include ${DEPENDS}
