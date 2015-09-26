
SRC = obj/main.o
EXE = bin/main
T = obj/TrainFile.o
EXE_TEST = bin/tests
TEST = obj/tests.o

# by default, make only compile bin
bin: $(EXE)
test: $(EXE_TEST)

tryTest: test
	$(EXE_TEST)

$(EXE_TEST): src/tests.cpp
	g++ -o $(EXE_TEST) -Wall src/tests.cpp

# link main.cpp and Header
$(EXE): $(SRC) $(T)
	g++ -o $(EXE) -Wall $(SRC) $(T)

# compile main.cpp
$(SRC): src/main.cpp
	g++ -c -o obj/main.o -Wall -I inc/ src/main.cpp

# compile TrainFile.cpp
$(T): src/TrainFile.cpp
	g++ -c -o $(T) -Wall -I inc/ src/TrainFile.cpp

clean:
	@- rm -f bin/*
	@- rm -f obj/*.o
