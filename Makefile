CXX=g++
CXXFLAGS=-Wall -O2 -DNDEBUG -I include -std=c++2a
LDFLAGS=-lmingw32 -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_mixer

SRC=src
OBJ=obj
BIN=bin

SRCS=$(wildcard $(SRC)/*.cc)
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))
DEPENDS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.d, $(SRCS))

RUNTIME_LIB=$(BIN)/libcookie.dll
STATIC_LIB=$(BIN)/cookie.a
BINS=$(RUNTIME_LIB) $(STATIC_LIB)

.PHONY: all clean

all: $(BINS)

-include $(DEPENDS)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) $(CXXFLAGS) -c -MMD -MP -o $@ $<

$(RUNTIME_LIB): $(OBJS)
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $@ $^ $(LDFLAGS)

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

clean:
	$(RM) $(OBJ)/*.o $(OBJ)/*.d $(BIN)/*.dll $(BIN)/*.a