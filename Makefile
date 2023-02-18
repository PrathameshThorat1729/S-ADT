# Building Commands
AR=ar
CXX=g++
CFLAGS=-Iinclude/ -g -Wall -std=c++11

# Variables for Building
SRC=src
OBJ=obj
LIB=lib
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
LIBS=$(patsubst $(OBJ)/%.o, $(LIB)/lib%.a, $(OBJS))
ILIBS=$(patsubst $(OBJ)/%.o,-l%, $(OBJS))

# Variables for Test
TEST=test
TESTBIN=$(TEST)/bin

# To not delete my Object Files
.SECONDARY: $(OBJS)

# Make Debugging Build
all: $(OBJ) $(LIB) $(LIBS)

# Make Release Build
release:CFLAGS=-Iinclude/ -Wall -std=c++11 -DNDEBUG -O2
release: clean
release: all

# Building Libraries
$(LIB)/lib%.a: $(OBJ)/%.o
	$(AR) rvs $@ $?

# Building Objects
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CFLAGS) $? -c -o $@

# Building and Running Tests Binaries
$(TEST)/%: $(OBJ) $(LIB) $(TESTBIN) $(LIB)/lib%.a
	$(CXX) $(CFLAGS) -L$(LIB)/ $@.test.cpp -o $(patsubst $(TEST)/%, $(TESTBIN)/%, $@) $(ILIBS)
	@echo "=========="
	@./$(TESTBIN)/$(patsubst $(TEST)/%,%, $@)
	@echo "=========="

# Creating Directies
$(OBJ):
	mkdir $(OBJ)

$(LIB):
	mkdir $(LIB)

$(TESTBIN):
	mkdir $(TESTBIN)

# Cleaning Project
clean:
	rm -rf $(LIB) $(OBJ) $(TESTBIN)