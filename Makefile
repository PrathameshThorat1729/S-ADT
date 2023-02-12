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
$(LIB)/%.a: $(OBJS)
	$(AR) rvs $@ $?

# Building Objects
$(OBJ)/%.o: $(SRCS)
	$(CXX) $(CFLAGS) $? -c -o $@

# Building and Running Tests Binaries
$(TEST)/%: $(OBJ) $(LIB) $(TESTBIN) $(LIB)/lib%.a
	$(CXX) $(CFLAGS) -L$(LIB)/ $@.test.cpp -o $(patsubst $(TEST)/%, $(TESTBIN)/%, $@) -l$(patsubst $(TEST)/%,%, $@)
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