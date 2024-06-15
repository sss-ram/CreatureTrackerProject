CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I"C:/Users/ssrin/anaconda3/Library/mingw-w64/include"

TARGET = main
OBJS = main.o creature.o creature_type_stats.o creature_tracker.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $

main.o: main.cpp creature.h creature_type_stats.h creature_tracker.h
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp

creature.o: creature.cpp creature.h
	$(CXX) $(CXXFLAGS) -c -o $@ creature.cpp

creature_type_stats.o: creature_type_stats.cpp creature_type_stats.h
	$(CXX) $(CXXFLAGS) -c -o $@ creature_type_stats.cpp

creature_tracker.o: creature_tracker.cpp creature_tracker.h bs_tree.hpp hash_table.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ creature_tracker.cpp

clean:
	rm -f $(TARGET) $(OBJS)
