CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRCDIR = src
BUILDDIR = bin

SOURCES = $(SRCDIR)/matrix.cpp $(SRCDIR)/main.cpp
TEST_SOURCES = $(SRCDIR)/matrix.cpp $(SRCDIR)/test.cpp

all: matrix_app test_app

matrix_app: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o matrix_app $(SOURCES)

test_app: $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -o test_app $(TEST_SOURCES)

docs:
	doxygen Doxyfile

clean:
	rm -f matrix_app test_app
	rm -rf docs/html docs/latex

.PHONY: all docs clean