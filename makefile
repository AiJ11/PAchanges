# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Bison and Flex
BISON = bison
FLEX = flex

# Output Executable
TARGET = parser

# Default target
all: $(TARGET)

# Generate Bison Files
parser.tab.cc parser.tab.hh: parser.yy
	$(BISON) -d parser.yy -o parser.tab.cc

# Generate Flex File
lexer.yy.cc: lexer.ll parser.tab.hh
	$(FLEX) lexer.ll

# Compile sources
parser.tab.o: parser.tab.cc ast.hh
	$(CXX) $(CXXFLAGS) -c parser.tab.cc -o parser.tab.o

lexer.yy.o: lexer.yy.cc parser.tab.hh ast.hh
	$(CXX) $(CXXFLAGS) -c lexer.yy.cc -o lexer.yy.o

ast.o: ast.cc ast.hh
	$(CXX) $(CXXFLAGS) -c ast.cc -o ast.o

main.o: main.cc ast.hh parser.tab.hh
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

# Link the Parser
$(TARGET): parser.tab.o lexer.yy.o ast.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) parser.tab.o lexer.yy.o ast.o main.o

# Clean Everything
clean:
	rm -f parser.tab.cc parser.tab.hh lexer.yy.cc $(TARGET) *.o

# Phony targets
.PHONY: all clean
