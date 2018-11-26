CXX=g++
CXXFLAGS+=-Wall $(GXX_FLAGS)
CXXFLAGS+=-g
CXXFLAGS+= -std=c++11
LOUD_FLAGS=-DLOUD

DEP_FLAGS=-MMD

EXECNAME=pso.out

EXECNAME_LOUD = $(EXECNAME)

DEP_FLAGS+=-MP
loud: DEP_FLAGS+=$(LOUD_FLAGS)

CXXFLAGS+=$(DEP_FLAGS)

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)


all: $(EXECNAME)

$(EXECNAME): $(OBJ)
	$(CXX) $(LFLAGS) $? -o $@

$(EXECNAME_LOUD): $(OBJ)
	$(CXX) $(LOUD_FLAGS) $? -o $@

.PHONY: clean run loud

clean:
	rm -f $(EXECNAME) $(OBJ) $(DEP)

run: $(EXECNAME)
	#rm -f $(OBJ) $(DEP)
	./$(EXECNAME)

loud: $(EXECNAME_LOUD)
	#rm -f $(OBJ) $(DEP)
	./$(EXECNAME_LOUD)

-include $(DEP)