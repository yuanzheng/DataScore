
SRC = obj/main.o
EXE = bin/main

# by default, make only compile bin
bin: $(EXE)


# link main.cpp and Header
$(EXE): $(SRC)
	g++ -o $(EXE) -Wall $(SRC)

# compile main.cpp
$(SRC): src/main.cpp
	g++ -c -o obj/main.o -Wall -I inc/ src/main.cpp


clean:
	@- rm -f bin/*
	@- rm -f obj/*.o
