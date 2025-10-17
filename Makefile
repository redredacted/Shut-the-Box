CXX ?= clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

SRCS = main.cpp ShutBox.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = shutbox

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
