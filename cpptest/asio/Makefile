# 注释
CXX = g++
BUILD_INCS = -I/usr/local/include

export BUILD_HOME_DIR = $(shell pwd)
# export BUILD_OUT_DIR  = $(BUILD_HOME_DIR)/bin
# export BUILD_OUT_DIR  = $(BUILD_HOME_DIR)

PROGRAM = Main
LIBS    = -L/usr/local/lib -lboost_system
SOURCE  = $(wildcard *.cpp)
OBJS 	= $(patsubst %.cpp,%.o, $(SOURCE)) 

%.o: %.cpp
	$(CXX) -c $(BUILD_INCS) -o $@ $?

$(PROGRAM):$(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS) $(PROGRAM)































