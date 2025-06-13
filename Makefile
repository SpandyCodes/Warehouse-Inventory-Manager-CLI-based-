CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

SRCS = main.cpp Product.cpp InventoryManager.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = inventory_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)