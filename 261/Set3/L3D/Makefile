TARGET = L3D
SRC_FILES = main.cpp test_suite.cpp array_functions.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
test_suite.o: test_suite.cpp test_suite.h array_functions.cpp array_functions.h
array_functions.o: array_functions.cpp array_functions.h
main.o: main.cpp test_suite.h