DEP = Utilities/Utilities.cpp String/String.cpp
CLASS = String

main: $(DEP) Main.cpp
	g++ -std=c++14 -o main $(DEP) Main.cpp

test: $(DEP) catch_amalgamated.cpp $(CLASS)/$(CLASS).Test.cpp
	g++ -std=c++14 -o test $(DEP) catch_amalgamated.cpp $(CLASS)/$(CLASS).Test.cpp
	./test

clean: 
	rm -f test

 