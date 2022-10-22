CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.cpp llrec.o 
	$(CXX) $(CXXFLAGS) $(DEFS) $^ -o $@

llrec.o: llrec.cpp stack.h llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c $< -o $@

clean:
	rm -f *.o rh llrec_test *~

.PHONY: clean 

#BIN_DIR = exe
#CXX = g++
#CPPFLAGS = -g -Wall -Ilib

#all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/pokemon

#$(BIN_DIR)/pokemon: src/main.cpp $(BIN_DIR)/attackMove.o $(BIN_DIR)/battle.o $(BIN_DIR)/pokemon.o
#	$(CXX) $(CPPFLAGS) $^ -o $@

#$(BIN_DIR)/attackMove.o: src/attackMove.cpp lib/attackMove.h
#	$(CXX) $(CPPFLAGS) -c $< -o $@

#$(BIN_DIR)/battle.o: src/battle.cpp lib/battle.h
#	$(CXX) $(CPPFLAGS) -c $< -o $@

#$(BIN_DIR)/pokemon.o: src/pokemon.cpp lib/pokemon.h
#	$(CXX) $(CPPFLAGS) -c $< -o $@