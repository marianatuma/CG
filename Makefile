CXXFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LDLIBS = $(shell pkg-config --libs gtk+-3.0)

vpl_wexecution: cohenSutherland.cpp displayFile.cpp graphObj.cpp main.cpp noClipping.cpp point.cpp polygon.cpp sutherlandHodgeman.cpp viewport.cpp window.cpp
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $@
